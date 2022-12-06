%token A
%%
start:  E    {printf("VALID\n");return 0;}
E:  E '+' T |E '-' T | T
T:  T '*' F | T '/' F | F
F:  '(' E ')' | B
B:  '-' A | '+' A | A
%%
#include "lex.yy.c"
int main(){
    return yyparse();
}
int yyerror(char *s){
    printf("INVALID\n");
}
