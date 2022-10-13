#include <stdio.h>

void stage1(char input[50], int var);
void stage2(char input[50], int var);
void stage3(char input[50], int var);
void stage4(char input[50], int var);
void stage5(char input[50], int var);

void stage1(char input[50], int var)
{
    if(input[var] == 'a')
        stage2(input, var+1);
    else if(input[var] == 'b')
        stage1(input, var+1);
    else if(input[var] == '\0')
        printf("Invalid String\n");
}

void stage2(char input[50], int var)
{
    if(input[var] == 'a')
        stage2(input, var+1);
    else if(input[var] == 'b')
        stage3(input, var+1);
    else if(input[var] == '\0')
        printf("Invalid String\n");
}

void stage3(char input[50], int var)
{
    if(input[var] == 'a')
        stage4(input, var+1);
    else if(input[var] == 'b')
        stage1(input, var+1);
    else if(input[var] == '\0')
        printf("Invalid String\n");
}

void stage4(char input[50], int var)
{
    if(input[var] == 'a')
        stage2(input, var+1);
    else if(input[var] == 'b')
        stage5(input, var+1);
    else if(input[var] == '\0')
        printf("Invalid String\n");
}

void stage5(char input[50], int var)
{
    printf("Valid String\n");
}

void main()
{
    char input[50];
    printf("Enter String\n");
    scanf("%s",input);
    stage1(input, 0);
}