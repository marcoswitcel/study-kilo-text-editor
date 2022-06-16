# Estudo e implementação do editor de texto baseado em terminal chamado Kilo

O nome do editor é [Kilo](https://github.com/antirez/kilo), desenvolvido pelo usuário [Antirez](https://github.com/antirez). Para mais detalhes sobre o editor segue o link do post original realizado no blog pessoal: [http://antirez.com/news/108](http://antirez.com/news/108).

Para reimplementar o editor segui o excelente tutorial disponibilizado aqui: [https://viewsourcecode.org/snaptoken/kilo/](https://viewsourcecode.org/snaptoken/kilo/). Tutorial desenvolvido de forma open-source no GitHub, pelo usuário: [https://github.com/snaptoken](https://github.com/snaptoken).

Vim a conhecer esse incrível tutorial graças a uma publicação que li no Medium: [https://timsneath.medium.com/windows-fun-with-dart-ffi-687c4619e78d](https://timsneath.medium.com/windows-fun-with-dart-ffi-687c4619e78d).

## Descrição do editor

* Mais ou menos 1000 linhas de código C;
* Sem dependências além da biblioteca padrão;
* Funcionalidades
  * Destaque de Síntaxe
  * Procura de texto
  * Teclas de atalhos e comandos
  * Barra com informação de linha e coluna

## Referências

### Antirez

* Publicação original aonde Antirez descreve o processo e os motivos da criação do editor: [http://antirez.com/news/108](http://antirez.com/news/108)
* Blog do Antirez: [http://antirez.com/latest/0](http://antirez.com/latest/0)
* GitHub do Antirez: [https://github.com/antirez](https://github.com/antirez)
* Código fonte do editor original: [https://github.com/antirez/kilo](https://github.com/antirez/kilo)

### Snaptoken (tutorial)

* Tutorial que reproduz os passos necessários para implementar o editor: [https://viewsourcecode.org/snaptoken/kilo/](https://viewsourcecode.org/snaptoken/kilo/)
* GitHub do Snaptoken: [https://github.com/snaptoken](https://github.com/snaptoken)
* Código fonte da versão usada para o tutorial: [https://github.com/snaptoken/kilo-src](https://github.com/snaptoken/kilo-src)

### Medium do Tim Sneath 

* Publicação de Tim Sneath no Medium: [https://timsneath.medium.com/windows-fun-with-dart-ffi-687c4619e78d](https://timsneath.medium.com/windows-fun-with-dart-ffi-687c4619e78d)

### Referências Técnicas

* Software Flow Control: [https://en.wikipedia.org/wiki/Software_flow_control](https://en.wikipedia.org/wiki/Software_flow_control)
* VT100: [https://en.wikipedia.org/wiki/VT100](https://en.wikipedia.org/wiki/VT100)
* VT100 User Guide: [https://vt100.net/docs/vt100-ug/chapter3.html](https://vt100.net/docs/vt100-ug/chapter3.html)
  * [https://vt100.net/docs/vt100-ug/chapter3.html#ED](https://vt100.net/docs/vt100-ug/chapter3.html#ED)
  * [https://vt100.net/docs/vt100-ug/chapter3.html#CUP](https://vt100.net/docs/vt100-ug/chapter3.html#CUP)
  * [https://vt100.net/docs/vt100-ug/chapter3.html#CUF](https://vt100.net/docs/vt100-ug/chapter3.html#CUF)
  * [https://vt100.net/docs/vt100-ug/chapter3.html#CUD](https://vt100.net/docs/vt100-ug/chapter3.html#CUD)
  * [https://vt100.net/docs/vt100-ug/chapter3.html#DSR](https://vt100.net/docs/vt100-ug/chapter3.html#DSR)
  * [https://vt100.net/docs/vt100-ug/chapter3.html#CPR](https://vt100.net/docs/vt100-ug/chapter3.html#CPR)
  * [https://vt100.net/docs/vt100-ug/chapter3.html#SM](https://vt100.net/docs/vt100-ug/chapter3.html#SM)
  * [https://vt100.net/docs/vt100-ug/chapter3.html#RM](https://vt100.net/docs/vt100-ug/chapter3.html#RM)
  * [https://vt100.net/docs/vt100-ug/chapter3.html#S3.3.4](https://vt100.net/docs/vt100-ug/chapter3.html#S3.3.4)
  * [https://vt100.net/docs/vt100-ug/chapter3.html#SGR](https://vt100.net/docs/vt100-ug/chapter3.html#SGR)
* Ncurses: [https://en.wikipedia.org/wiki/Ncurses](https://en.wikipedia.org/wiki/Ncurses)
* Terminfo database: [https://en.wikipedia.org/wiki/Terminfo](https://en.wikipedia.org/wiki/Terminfo)
* Feature Test Macro: [https://www.gnu.org/software/libc/manual/html_node/Feature-Test-Macros.html](https://www.gnu.org/software/libc/manual/html_node/Feature-Test-Macros.html)
* Unix Time: [https://en.wikipedia.org/wiki/Unix_time](https://en.wikipedia.org/wiki/Unix_time)
* Variadic Function: [https://en.wikipedia.org/wiki/Variadic_function](https://en.wikipedia.org/wiki/Variadic_function)
* ASCII Table: [https://www.asciitable.com/](https://www.asciitable.com/)
* One-pass compiler: [https://en.wikipedia.org/wiki/One-pass_compiler](https://en.wikipedia.org/wiki/One-pass_compiler)
* ANSI escape code: [https://en.wikipedia.org/wiki/ANSI_escape_code](https://en.wikipedia.org/wiki/ANSI_escape_code)
