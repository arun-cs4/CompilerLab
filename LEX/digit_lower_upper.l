symbol [!@#$%^&*()_+-=\|?<>]

%%
[0-9] {printf("DIGIT");}
[a-z] {printf("LOWERCASE");}
[A-Z] {printf("UPPERCASE");}
{symbol} {printf("SYMBOL");}
%%

int yywrap(void){}
int main(){
    yylex();
    return 0;
}