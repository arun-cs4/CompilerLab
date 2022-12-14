/*
    E –> T E’ 
    E’ –> + T E’ |- T E' | e 
    T –> F T’ 
    T’ –> * F T’ | / F T' | e 
    F –> ( E ) | id

*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int E(char input[100]);
int EPrime(char input[100]);
int T(char input[100]);
int TPrime(char input[100]);
int F(char input[100]);

int var = 0;

int E(char input[100])
{
    if (T(input))
        if (EPrime(input))
            return 1;
        else
            return 0;
    else
        return 0;
}

int EPrime(char input[100])
{
    if (input[var] == '+' || input[var] == '-')
    {
        var++;
        if (T(input))
            if (EPrime(input))
                return 1;
            else
                return 0;
        else
            return 0;
    }
    else
    {
        return 1;
    }

}

int T(char input[100])
{
    if (F(input))
        if(TPrime(input))
            return 1;
        else
            return 0;
    else
        return 0;
}

int TPrime(char input[100])
{
    if (input[var] == '*' || input[var] == '/')
    {
        var++;
        if (F(input))
            if (TPrime(input))
                return 1;
            else
                return 0;
        else
            return 0;
    }
    else
    {
        return 1;
    }
}

int F(char input[100])
{
    if (input[var] == '(')
    {
        var++;
        if (E(input))
        {   
            if (input[var] == ')')
            {
                var++;
            }
        }
    }
    else if (isalpha(input[var]))
    {
        var++;
        return 1;
    }
    else if(isdigit(input[var]))
    {
		while(isdigit(input[var]))
			var++;
		return 1;	
	}
    else
    {
        return 0;
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
