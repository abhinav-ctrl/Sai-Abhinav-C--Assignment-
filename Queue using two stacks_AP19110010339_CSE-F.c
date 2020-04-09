/* Implementation of Queue using two stacks */
#include <stdio.h>
#include <stdlib.h>
void push1(int);
void push2(int);
int pop1();
int pop2();
void enqueue();
void dequeue();
void display();
void create();
int s1[50], s2[50];
int top1 = -1, top2 = -1;
int count = 0;
int main()
{
    int ch;
    printf("\nImplementation of queue using two stacks\n\n");
    printf("\n1.Enqueue");
    printf("\n2.dequeue");
    printf("\n3.display");
    printf("\n4.exit");
    printf("\n");
    create();
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid Choice\n");
        }}}
void create()
{
    top1 = top2 = -1;
}
void push1(int val)
{
    s1[++top1] = val; 
}
int pop1()
{
    return(s1[top1--]); 
}
void push2(int val)
{
    s2[++top2] = val; 
}
int pop2()
{
    return(s2[top2--]); 
}
void enqueue()
{
    int ele, i;
    printf("Enter the data : ");
    scanf("%d", &ele);
    push1(ele); 
    count++;
}
void dequeue()
{
    int i;
    for (i = 0;i <= count;i++)
    {
        push2(pop1());
    }
    pop2(); 
    count--;
    for (i = 0;i <= count;i++)
    {
        push1(pop2()); 
    }}
void display()
{
    int i;
    if(top1 == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nElements in the queue are : ");
        for (i = 0;i <= top1;i++)
        {
            printf(" %d ", s1[i]);
        }
        printf("\n");
}}
