%%
"//".*
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]
%%
int yywrap(void){}
int main()
{
    yyin=fopen("filein.c", "r");
    yyout=fopen("fileout", "w");
    yylex();
    return 0;
}
