%%
abb*ab*(ab*a)*b* {printf("TRUE");}
(.)* {printf("FALSE");}
%%

int yywrap(void){}
int main(){
    yylex();
    return 0;
}