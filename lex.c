#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);
    return (false);
}

bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '>' ||
        ch == '<' || ch == '=' || ch == '%')
        return (true);
    return (false);
}

int isKeyword(char str[100], int var)
{
	char keywords[][20] ={"auto","double","int","struct","break","else","long",
						"switch","case","enum","register","typedef",
						"char","extern","return","union","continue","for","signed","void",
						"do","if","static","while","default","goto","goto","volatile","const","float","short",
						"unsigned"};
	
	char tmp[20];
	if (str[var]=='\0')
	{
		return 0;
	}
	int start = var, end = var, l;
	if (isalpha(str[var] != 0))
	{
		if(isalpha(str[var]) != 0)
		{
			do
			{
				end++;
			}while(isDelimiter(str[end]) == false);
		}

		l = end-start;
		for (int i=0; i<l; i++)
		{
			tmp[i]=str[start+i];
		}
		for (int i=0; i<32; i++)
		{
			if (strcmp(tmp, keywords[i])==0)
			{
				printf ("%s is a keyword\n", tmp);
			}
			else
			{
				printf ("%s is an Identifier\n", tmp);
			}
			
		}
		isKeyword(str, end);
	}
	else if(isdigit(str[var] != 0))
	{
		if(isdigit(str[var] != 0))
		{
			do
			{
				end++;
			}while(isdigit(str[end]) != 0);
		}
		l = end-start;
		for (int i=0; i<l; i++)
		{
			tmp[i]=str[start+i];
		}
		for (int i=0; i<32; i++)
		{
			int n = atoi(tmp);
			printf("%d is a number\n", n);
		}
		isKeyword(str, end);
	}
	else if(str[var] == ' ')
	{
		isKeyword(str, var+1);
	}
	else if(isOperator(str[var])==true)
	{
		if(isOperator(str[var+1])==true)
		{
			printf("%c%c\n is an operator",str[var],str[var+1]);
			isKeyword(str, var+2);
		}
		else
		{
			printf("%c\n is an operator",str[var]);
			isKeyword(str, var+1);
		}
	}
}

void main()
{
	FILE *fp;
	char str[100], ch;
	char *token;
	int i = 0;
	fp = fopen("input.txt", "r");
	do
	{
    	ch = fgetc(fp);
		str[i] = ch;
		++i;
    }while (ch != EOF);
	str[i]='\0';
	fclose(fp);
	isKeyword(str, 0);
}
