%%
"if"|"else"|"while"|"int"|"float" {printf("Keyword %s \n",yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {printf("Identifier %s ",yytext);}
"<="|"=="|"="|"+"|"-"|"*" {printf("Operator %s \n",yytext);}
[0-9]*"."[0-9]+ {printf("Float Literal %s \n",yytext);}
[0-9]+ {printf("Integer Literal %s \n",yytext);}
"//".*
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]
%%
int yywrap(){}
int main(){
FILE *ptr;
ptr=fopen("demo.c","r");
yyin=ptr;
yylex();
}
