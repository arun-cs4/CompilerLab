
%%
[0-9]+   {sscanf(yytext, "%d", &yylval);return(A);}
.   return (yytext[0]);
\n  return ('\n');
%%
int yywrap(){
    return 1;
}