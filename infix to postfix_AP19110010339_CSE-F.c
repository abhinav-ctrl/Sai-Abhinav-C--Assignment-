/* Infix to postfix conversion using stack */
#include<stdio.h>
#include <ctype.h>
#define size 50
char s[size];
int top = -1;
void push(char a)
{
    s[++top] = a;
}
 
char pop()
{
    if(top == -1)
    {
        return -1;
    }
    else
    {
        return s[top--];
    }
}
 
int priority(char a)
{
    if(a == '(')
    {
        return 0;
    }
    if(a == '+' || a == '-')
    {
        return 1;
    }
    if(a == '*' || a == '/')
    {
        return 2;
    }
}
 
void main()
{
    char sen[20];
    char *p, a;
    printf("Enter the expression : ");
    scanf("%s",sen);
    p = sen;
    while(*p != '\0')
    {
        if(isalnum(*p))
        {
            printf("%c",*p);
        }
        else if(*p == '(')
        {
            push(*p);
        }
        else if(*p == ')')
        {
            while((a = pop()) != '(')
                printf("%c", a);
        }
        else
        {
            while(priority(s[top]) >= priority(*p))
                printf("%c",pop());
            push(*p);
        }
        p++;
    }
    while(top != -1)
    {
        printf("%c",pop());
    }
}
