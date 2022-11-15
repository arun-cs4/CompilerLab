%%
(a[a|b]*a)|(b[a|b]*b)   {printf("TRUE");}
(.)* {printf("FALSE");}
%%

int yywrap(void){}
int main(){
    yylex();
    return 0;
}