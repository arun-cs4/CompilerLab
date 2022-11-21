#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

FILE *ptrKeywords, *ptrOperators, *ptrIdentifier, *fp;
char buf[100];
void checkIdentifier()
{
    char tokens[][10] = {"include", "scanf", "printf", "stdio.h", "string.h", "main", "stdlib.h"};
    if (isdigit(buf[0]) != 0 || buf[0] == '.' || buf[0] == '"')
        return;
    for (int i = 0; i < 7; ++i)
    {
        if (strcmp(buf, tokens[i]) == 0)
        {
            fgets(buf, sizeof(buf), fp);
            return;
        }
    }
    fputs(buf, ptrIdentifier);
    fputs("\n", ptrIdentifier);
}

void checkKeyword()
{
    char keywords[][10] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "else",
                           "enum", "extern", "float", "for", "goto", "if", "int", "long",
                           "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
                           "unsigned", "void", "volatile", "while", "_Packed"};

    for (int i = 0; i < 32; ++i)
    {
        if (strcmp(buf, keywords[i]) == 0)
        {
            fputs(buf, ptrKeywords);
            fputs("\n", ptrKeywords);
            return;
        }
    }

    checkIdentifier();
}

void checkOperator(char ch)
{
    char operators[] = "+-*/=";
    char special[] = " \n\t;{},)([]|%#&<!>$@";
    for (int i = 0; i < strlen(special); ++i)
    {
        if (ch == special[i])
        {
            if (buf[0] != '\0')
            {
                checkKeyword();
                memset(buf, '\0', strlen(buf));
            }
            return;
        }
    }
    for (int i = 0; i < strlen(operators); ++i)
    {
        if (ch == operators[i])
        {
            if (ch == '/' && fgetc(fp) == '/') // checking for comments
            {
                char temp[100];
                fgets(temp, sizeof(temp), fp); // move fp to next line
                return;
            }
            fputc(ch, ptrOperators);
            fputc('\n', ptrOperators);
            if (buf[0] != '\0')
            {
                checkKeyword();
                memset(buf, '\0', strlen(buf));
            }
            return;
        }
    }
    strncat(buf, &ch, 1);
}

int main()
{
    char ch, fname[100];
    printf("enter the file name\n");
    scanf("%s", fname);
    ptrOperators = fopen("operators.txt", "w+");
    ptrIdentifier = fopen("identifiers.txt", "w+");
    ptrKeywords = fopen("keywords.txt", "w+");
    fp = fopen(fname, "r");
    if (fp == NULL)
        printf("error while opening the file\n");
    while ((ch = fgetc(fp)) != EOF)
    {
        checkOperator(ch);
    }
    fseek(ptrIdentifier, 0, SEEK_SET);
    fseek(ptrKeywords, 0, SEEK_SET);
    fseek(ptrOperators, 0, SEEK_SET);
    printf("\nKEYWORDS\n");
    while (fgets(buf, sizeof(buf), ptrKeywords))
    {
        printf("%s", buf);
    }
    printf("\nOPERATORS\n");
    while (fgets(buf, sizeof(buf), ptrOperators))
    {
        printf("%s", buf);
    }
    printf("\nIDENTIFIERS\n");
    while (fgets(buf, sizeof(buf), ptrIdentifier))
    {
        printf("%s", buf);
    }
    fclose(fp);
    fclose(ptrIdentifier);
    fclose(ptrKeywords);
    fclose(ptrOperators);
}
