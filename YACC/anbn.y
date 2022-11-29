%token A B
%%
start:  anbn '\n'   {printf("VALID\n");return 0;}
anbn:   A B | A anbn B ;
%%
#include "lex.yy.c"
int main(){
    return yyparse();
}
int yyerror(char *s){
    fprintf(stderr, "%s\n",s);  
}