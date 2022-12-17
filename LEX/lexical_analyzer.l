%%
"if"|"else"|"while"|"int"|"float"	{printf("Keyword %s \n",yytext);}
[$_a-zA-Z][$_a-zA-Z0-9]*	{printf("Identifier %s \n",yytext);}
">="|"<="|"=="|"="|"+"|"-"|"*"|"/"	{printf("Operator %s \n",yytext);}
[0-9]*"."[0-9]+ {printf("Float Literal %s \n",yytext);}
[0-9]+ {printf("Integer Literal %s \n",yytext);}
"//".*
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]
.
%%
int yywrap(){}
int main(){
FILE *ptr;
ptr=fopen("input.c","r");
yyin=ptr;
yylex();
}
