%token A

%%
start:  E    {printf("%d\n",$1);return 0;}
E:  E '+' T { $$ = $1 + $3; } | E '-' T { $$ = $1 - $3; } | T { $$ = $1; }
T:  T '*' F { $$ = $1 * $3; } | T '/' F { $$ = $1 / $3; } | F { $$ = $1; }
F:  '(' E ')' { $$ = $2; } | B { $$ = $1; }
B:  '-' A { $$ =  -$2; } | '+' A { $$ = $2; } | A { $$ = $1; }
%%
#include "lex.yy.c"
int main(){
    return yyparse();
}
int yyerror(char *s){
    printf("INVALID\n");
}