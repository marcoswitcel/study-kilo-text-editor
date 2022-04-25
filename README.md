# Estudo e implementação do editor de texto baseado em terminal Kilo

O editor é [Kilo](https://github.com/antirez/kilo) do usuário [Antirez](https://github.com/antirez).

## Descrição do editor

* Mais ou menos 1000 linhas de código C;
* Sem dependências além da biblioteca padrão;
* Funcionalidades
  * Destaque de Síntaxe
  * Procura de texto
  * Teclas de atalhos e comandos
  * Barra com informação de linha e coluna

## Referências

* Publicação original aonde Antirez descreve o processo e os motivos da criação do editor: [http://antirez.com/latest/0](http://antirez.com/latest/0)
* Tutorial que reproduz os passos necessários para implementar o editor: [https://viewsourcecode.org/snaptoken/kilo/](https://viewsourcecode.org/snaptoken/kilo/)
* Software Flow Control: [https://en.wikipedia.org/wiki/Software_flow_control](https://en.wikipedia.org/wiki/Software_flow_control)
* VT100: [https://en.wikipedia.org/wiki/VT100](https://en.wikipedia.org/wiki/VT100)
* VT100 User Guide: [https://vt100.net/docs/vt100-ug/chapter3.html](https://vt100.net/docs/vt100-ug/chapter3.html)
* Ncurses: [https://en.wikipedia.org/wiki/Ncurses](https://en.wikipedia.org/wiki/Ncurses)
* Terminfo database: [https://en.wikipedia.org/wiki/Terminfo](https://en.wikipedia.org/wiki/Terminfo)