/*** includes ***/

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

/*** defines ***/

// In other words, it sets the upper 3 bits of the character to 0
#define CTRL_KEY(k) ((k) & 0x1f)

/*** data ***/

struct editorConfig {
  struct termios orig_termios;
};

struct editorConfig E;

/*** terminal ***/

void die(const char *s) {
  write(STDOUT_FILENO, "\x1b[2J", 4);
  write(STDOUT_FILENO, "\x1b[H", 3);
  
  perror(s);
  exit(1);
}

void disableRawMode() {
  // This is because of the TCSAFLUSH option being passed to tcsetattr() when the program exits
  // it discards any unread input before applying the changes to the terminal
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.orig_termios) == -1)
    die("tcsetattr");
}

void enableRawMode() {
  if (tcgetattr(STDIN_FILENO, &E.orig_termios) == -1) die("tcgetattr");
  // atexit() comes from <stdlib.h>.
  // We use it to register our disableRawMode() function to be called automatically when the program exits
  atexit(disableRawMode);
  struct termios raw = E.orig_termios;
  raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
  raw.c_oflag &= ~(OPOST);
  raw.c_cflag |= (CS8);
  raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 1;

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) die("tcsetattr");
}

/**
 * @brief editorReadKey()’s job is to wait for one keypress, and return it.
 * Later, we’ll expand this function to handle escape sequences, which
 * involves reading multiple bytes that represent a single keypress, as is
 * the case with the arrow keys.
 * 
 * @return char 
 */
char editorReadKey() {
  int nread;
  char c;
  while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
    if (nread == -1 && errno != EAGAIN) die("read");
  }
  return c;
}

/*** output ***/

/**
 * @brief editorDrawRows() will handle drawing each row of the buffer of
 * text being edited. For now it draws a tilde in each row, which means
 * that row is not part of the file and can’t contain any text.
 */
void editorDrawRows() {
  int y;
  for (y = 0; y < 24; y++) {
    write(STDOUT_FILENO, "~\r\n", 3);
  }
}

void editorRefreshScreen() {
  write(STDOUT_FILENO, "\x1b[2J", 4);
  write(STDOUT_FILENO, "\x1b[H", 3);

  editorDrawRows();

  write(STDOUT_FILENO, "\x1b[H", 3);
}

/*** input ***/

/**
 * @brief editorProcessKeypress() waits for a keypress, and then handles it.
 * Later, it will map various Ctrl key combinations and other special keys
 * to different editor functions, and insert any alphanumeric and other
 * printable keys’ characters into the text that is being edited.
 */
void editorProcessKeypress() {
  char c = editorReadKey();
  switch (c) {
    case CTRL_KEY('q'):
      write(STDOUT_FILENO, "\x1b[2J", 4);
      write(STDOUT_FILENO, "\x1b[H", 3);
      exit(0);
      break;
  }
}

/*** init ***/

int main() {
  enableRawMode();

  while (1) {
    editorRefreshScreen();
    editorProcessKeypress();
  }
  return 0;
}
