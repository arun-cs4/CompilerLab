%%
[$_a-zA-Z][_a-zA-Z0-9]* {printf("TRUE");}
(.)* {printf("FALSE");}
%%

int yywrap(void){}
int main(){
    yylex();
    return 0;
}
