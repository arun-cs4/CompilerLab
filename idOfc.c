#include <stdio.h>
#include <ctype.h>

void stage1(char input[50], int var);
void stage2(char input[50], int var);
void stage3(char input[50], int var);

void stage1(char input[50], int var)
{
    if(isalpha(input[var]) != 0)
    {
        stage2(input, var+1);
    }
    else if(input[var] == '\0')
        printf("Invalid Identifier\n");
    else
        stage3(input, var+1);
}

void stage2(char input[50], int var)
{
    if(isalpha(input[var]) != 0  || isdigit(input[var]) != 0)
    {
        stage2(input, var+1);
    }
    else if(input[var] == '\0')
        printf("Valid Identifier\n");
    else
        stage3(input, var+1);
}

void stage3(char input[50], int var)
{
    printf("Invalid Identifier\n");
}

void main()
{
    char input[50];
    printf("Enter String\n");
    scanf("%s",input);
    stage1(input, 0);
}