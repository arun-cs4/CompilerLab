#include <stdio.h>

void stage1(char input[50], int var);
void stage2(char input[50], int var);
void stage3(char input[50], int var);

void stage1(char input[50], int var)
{
    if(input[var] == '0' || input[var] == '3' || input[var] == '6' || input[var] == '9')
        stage1(input, var+1);
    else if(input[var] == '1' || input[var] == '4' || input[var] == '7')
        stage2(input, var+1);
    else if(input[var] == '2' || input[var] == '5' || input[var] == '8')
        stage3(input, var+1);
    else if(input[var] == '\0')
        printf("Divisible by 3\n");
}

void stage2(char input[50], int var)
{
    if(input[var] == '0' || input[var] == '3' || input[var] == '6' || input[var] == '9')
        stage2(input, var+1);
    else if(input[var] == '1' || input[var] == '4' || input[var] == '7')
        stage3(input, var+1);
    else if(input[var] == '2' || input[var] == '5' || input[var] == '8')
        stage1(input, var+1);
    else if(input[var] == '\0')
        printf("Not Divisible by 3\n");
}

void stage3(char input[50], int var)
{
    if(input[var] == '0' || input[var] == '3' || input[var] == '6' || input[var] == '9')
        stage3(input, var+1);
    else if(input[var] == '1' || input[var] == '4' || input[var] == '7')
        stage1(input, var+1);
    else if(input[var] == '2' || input[var] == '5' || input[var] == '8')
        stage2(input, var+1);
    else if(input[var] == '\0')
        printf("Not Divisible by 3\n");
}

void main()
{
    char input[50];
    printf("Enter String\n");
    scanf("%s",input);
    stage1(input, 0);
}
