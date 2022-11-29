%%
[0-9]+   return (A);
.   return (yytext[0]);
\n  return ('\n');
%%
int yywrap(){
    return 1;
}