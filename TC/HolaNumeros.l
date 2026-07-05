%{
#include <stdio.h>
%}

%%

[0-9]+      { printf("hola mundo\n"); }

[a-zA-Z]+   { /* si escribe letras, no muestra nada */ }

[ \t\n]+    { /* ignorar espacios y saltos de línea */ }

.           { /* ignorar cualquier otro carácter */ }

%%

int main() {
    printf("Escribe numero para ver el mensaje:\n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}