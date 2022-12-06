%%
(int)[ ][$_a-zA-Z][$_a-zA-Z0-9]*([ ]*(=)[ ]*[0-9]+)?[ ]*(,[ ]*[$_a-zA-Z][$_a-zA-Z0-9]*([ ]*(=)[ ]*[0-9]+)?)*[ ]*(;)   {printf("VALID Int");}
(float)[ ][$_a-zA-Z][$_a-zA-Z0-9]*([ ]*(=)[ ]*[.]?[0-9]+)?[ ]*(,[ ]*[$_a-zA-Z][$_a-zA-Z0-9]*([ ]*(=)[ ]*[.]?[0-9]+)?)*[ ]*(;)   {printf("VALID Float");}
(float)[ ][$_a-zA-Z][$_a-zA-Z0-9]*([ ]*(=)[ ]*[0-9]+[.]?[0-9]*)?[ ]*(,[ ]*[$_a-zA-Z][$_a-zA-Z0-9]*([ ]*(=)[ ]*[0-9]+[.]?[0-9]*)?)*[ ]*(;)   {printf("VALID Float");}
(char)[ ][$_a-zA-Z][$_a-zA-Z0-9]*([ ]*(=)[ ]*(')[a-zA-Z]('))?[ ]*(,[ ]*[$_a-zA-Z][$_a-zA-Z0-9]*([ ]*(=)[ ]*(')[a-zA-Z]('))?)*[ ]*(;)   {printf("VALID Character");}
(.)*    {printf("Invalid variable declaration");}
%%
int yywrap(void){}
int main(){
    yylex();
    return 0;
}
