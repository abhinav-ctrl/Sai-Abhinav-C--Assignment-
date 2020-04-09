/* Reversing a string using stack */
#include <stdio.h>  
#include <string.h>  
#define capacity 100  
int top,s[capacity];  
void push(char a)
{  
  if(top == capacity-1)
  {  
    printf("stack is full");  
  }
  else 
  {  
    s[++top]=a;  
  }  
  
}  
void pop()
{
    printf("%c",s[top--]);  
}  
void main()  
{  
   char string[]="Abhinav";  
   int len = strlen(string);  
   int i;  
   for(i=0;i<len;i++)
   {
        push(string[i]);
   }
   for(i=0;i<len;i++)
   {
      pop();
   }
} 

