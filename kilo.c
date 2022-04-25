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

struct termios orig_termios;

/*** terminal ***/

void die(const char *s) {
  perror(s);
  exit(1);
}

void disableRawMode() {
  // This is because of the TCSAFLUSH option being passed to tcsetattr() when the program exits
  // it discards any unread input before applying the changes to the terminal
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
    die("tcsetattr");
}

void enableRawMode() {
  if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) die("tcgetattr");
  tcgetattr(STDIN_FILENO, &orig_termios);
  // atexit() comes from <stdlib.h>.
  // We use it to register our disableRawMode() function to be called automatically when the program exits
  atexit(disableRawMode);
  struct termios raw = orig_termios;
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
      exit(0);
      break;
  }
}

/*** init ***/

int main() {
  enableRawMode();

  while (1) {
    editorProcessKeypress();
  }
  return 0;
}
