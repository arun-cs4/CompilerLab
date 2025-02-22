## Steps to run lex file
1) Compile lex file -> lex fileName.l
2) You will get a file named lex.yy.c
3) Compile the c file -> gcc lex.yy.c
4) You will get a file named a.out
5) Run the file -> ./a.out 

## Steps to run lex and yacc file together
1) Compile lex file -> lex lexFileName.l
2) You will get a file named lex.yy.c
3) Compile the yacc file -> yacc yaccFileName.y
4) You will get a file named y.tab.c
5) Compile y.tab.c -> gcc y.tab.c
6) Run the file -> ./a.out
