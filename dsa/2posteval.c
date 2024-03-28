#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define MAX 10
void push(int);
int pop();
int stack[MAX];
int top =-1;
char ch;

void push(int element)
{
	if(top==MAX - 1)
       printf("stack overflow");
    else
    {
    	top=top+1;
		stack[top]=element;
	}
}
int pop()
{
	if(top==-1)
	  printf("stack underflow");
	else
	{
		ch=stack[top];
		top=top-1;
	}
	return ch;  
}
void display()
{
	int i=0;
	printf("\nstack status");
	for(i=0;i<=top;i++)
	    printf(" | %d ", stack[i]);
}
int main()
{
	char postfix[MAX]={'\0'}, element;
	int i, number1, number2, result;
	printf("Enter the postfix expression");
	scanf(" %s", postfix);
	printf("The postfix expression is %s", postfix);
	i=0;
	while(i<=strlen(postfix)-1)
	{
		element = postfix[i];
		if(isdigit(element))
		   push(element - '0');
	    else
	    {
	    	number1=pop();
	    	number2=pop();
	    	switch(element)
	    	{
	    		case '^':
	    			result=pow(number2,number1);
	    			break;
	    		case '/':
	    			result = number2 / number1;
	    			break;
	    		case '*':
	    			result = number2 * number1;
	    			break;
	    		case '+':
	    			result = number2 + number1;
	    			break;
	    		case '-':
	    			result = number2 - number1;
	    			break;
	    		
			}
			push(result);
		}
		display();
		i=i+1;
	}
    printf("The answer is %d", pop());
}
