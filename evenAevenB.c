#include <stdio.h>

void stage1(char input[50], int var);
void stage2(char input[50], int var);
void stage3(char input[50], int var);
void stage4(char input[50], int var);

void stage1(char input[50], int var)
{
    if(input[var] == 'a')
        stage2(input, var+1);
    else if(input[var] == 'b')
        stage4(input, var+1);
    else if(input[var] == '\0')
        printf("Valid String\n");
}

void stage2(char input[50], int var)
{
    if(input[var] == 'a')
        stage1(input, var+1);
    else if(input[var] == 'b')
        stage3(input, var+1);
    else if(input[var] == '\0')
        printf("Inalid String\n");
}

void stage3(char input[50], int var)
{
    if(input[var] == 'a')
        stage4(input, var+1);
    else if(input[var] == 'b')
        stage2(input, var+1);
    else if(input[var] == '\0')
        printf("Inalid String\n");
}

void stage4(char input[50], int var)
{
    if(input[var] == 'a')
        stage3(input, var+1);
    else if(input[var] == 'b')
        stage1(input, var+1);
    else if(input[var] == '\0')
        printf("Inalid String\n");
}

void main()
{
    char input[50];
    printf("Enter string\n");
    scanf("%s",input);
    stage1(input,0);
}