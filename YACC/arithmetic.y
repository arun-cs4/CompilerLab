%token A
%%
start:  E    {printf("VALID\n");return 0;}
E:  A '+' A | A '-' A | A '*' A | A '/' A ;
%%
#include "lex.yy.c"
int main(){
    return yyparse();
}
int yyerror(char *s){
    fprintf(stderr,"%s\n",s);
}