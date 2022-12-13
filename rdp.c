/*
    E –> T E’ 
    E’ –> + T E’ | e 
    T –> F T’ 
    T’ –> * F T’ | e 
    F –> ( E ) | id

*/

#include<stdio.h>
#include<string.h>

void E(char input[100]);
void EPrime(char input[100]);
void T(char input[100]);
void TPrime(char input[100]);
void F(char input[100]);

int var = 0;

void E(char input[100])
{
    T(input);
    EPrime(input);
}

void EPrime(char input[100])
{
    if (input[var] == '+')
    {
        var++;
        T(input);
        EPrime(input);
    }
    else
    {
        return;
    }
}

void T(char input[100])
{
    F(input);
    TPrime(input);
}

void TPrime(char input[100])
{
    if (input[var] == '*')
    {
        var++;
        F(input);
        TPrime(input);
    }
    else
    {
        return;
    }
}

void F(char input[100])
{
    if (input[var] == '(')
    {
        var++;
        E(input);
        if (input[var] == ')')
        {
            var++;
        }
    }
    else if (input[var] == 'a')
    {
        var++;
    }
}

void main()
{
    char input[100];
    printf("Enter string\n");
    scanf("%s",input);
    int len = strlen(input);
    input[len] = '$';
    E(input);
    if (input[var] == '$')
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }
}