%{
    int lcount = 1;
    int wcount = 1;
    int ccount = 0;
%}
%%
[\n]    {lcount++;wcount++;}
[\t' '] {wcount++;}
[a-zA-Z]    {ccount++;}
%%
int yywrap(void){}
int main()
{
    char filename[20];
    FILE *ptr;
    printf("Enter the filename : ");
    scanf("%s",filename);
    ptr=fopen(filename,"r");
    if(ptr==NULL)
    {
        printf("Error occured");
        return 0;
    }
    yyin=ptr;
    yylex();
    printf("Number of lines : %d\n",lcount);
    printf("Number of words : %d\n",wcount);
    printf("Number of characters : %d\n",ccount);
    return 0;
}
