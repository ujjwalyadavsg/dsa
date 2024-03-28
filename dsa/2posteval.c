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


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define SIZE 20
struct stack
{
 int top;
 float data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s,float item)
{
 s->data[++(s->top)]=item;
}
float pop(STACK *s)
{
 return s->data[(s->top)--];
}
float operate(float op1,float op2,char symbol)
{
 switch(symbol)
 {
 case '+':return op1+op2;
 case '-':return op1-op2;
 case '*':return op1*op2;
 case '/':return op1/op2;
 case '^':return pow(op1,op2);
 }
}
float eval(STACK *s,char prefix[SIZE])
{
 int i;
 char symbol;
 float res,op1,op2;
 for(i=strlen(prefix)-1;i>=0;i--)
 {
 symbol=prefix[i];
 if(isdigit(symbol))
 push(s,symbol-'0');
 else
 {
 op1=pop(s);
 op2=pop(s);
 res=operate(op1,op2,symbol);
 push(s,res);
 }
 }
 return pop(s);
}
int main()
{
 char prefix[SIZE];
 STACK s;
 float ans;
 s.top=-1;
 printf("\n Read prefix expr\n");
 scanf("%s",prefix);
 ans=eval(&s,prefix);
 printf("\n The final answer is %f\n",ans);
 return 0;
}