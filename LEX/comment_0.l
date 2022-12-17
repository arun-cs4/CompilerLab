%%
"/*"(.*"\n"*)*"*/"    {printf(yytext);printf("\n");}
"//".*[\n]  {printf(yytext);printf("\n");}
(.) {fprintf(yyout,"%s",yytext);}
%%
int yywrap(void){}
int main()
{
    char filename[20];
    FILE *ptr;
    printf("Enter the filename : ");
    scanf("%s",filename);
    ptr = fopen(filename,"r");
    if(ptr==NULL)
    {
        printf("Error occured");
        return 0;
    }
    yyin = ptr;
    yyout = fopen("output.c", "w"); 
    yylex();
    return 0;
}
