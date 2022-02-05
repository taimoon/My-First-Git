#ifndef POSLISH_NOTATION_H_INCLUDED
#define POSLISH_NOTATION_H_INCLUDED

#include"string.h"
#include"stack.h"
#define getArrLen(arr)(sizeof(arr)/sizeof(arr[0]))
const char opList[] = {'^','*','/','+','-'};
stackClass(char);
void printFunc(char val){
    printf("%c", val);
}
printStack(printFunc);

#define swap(a, b, temp)temp=a;a=b;b=temp;


int isOperator(char ch)
{
    for(int i = 0; i < getArrLen(opList); ++i)
        if(opList[i] == ch)
            return 1;
    return 0;
}
int precedence(char op)
{
    switch(op)
    {
    case '^':
        return 4;
        break;
    case '*':
    case '/':
        return 3;
        break;
    case '+':
    case '-':
        return 2;
        break;
    case '(':
    case ')':
        return 0;
        break;
    }
}

void postfixConverter(char infix[], char postfix[], int len){
    nodePtr opStack = NULL;
    int j = 0;
    for(int i = 0; i < len; ++i)
    {
        if(isOperator(infix[i]))
        {
            while(!(isEmpty(opStack))&& (precedence(top(opStack)) >= precedence(infix[i])))
            {
                postfix[j]=pop(&opStack);
                ++j;
            }
            push(&opStack, infix[i]);
        }
        else if(infix[i] == '(')
            push(&opStack, infix[i]);
        else if(infix[i] ==')')
        {
            while(top(opStack)!= '(')
            {
                postfix[j]=pop(&opStack);
                ++j;
            }
            pop(&opStack);
        }
        else
        {
            postfix[j]=infix[i];
            ++j;
        }
    }

    while(!(isEmpty(opStack)))
    {
        postfix[j] = pop(&opStack);
        ++j;
    }
    postfix[j] = '\0';
}
void prefixConverter(char infix[], char prefix[], int len){
    nodePtr opStack = NULL;
    int j = 0;
    for(int i = len-1; i >= 0; --i)
    {
        if(isOperator(infix[i]))
        {
            while(!(isEmpty(opStack))&& (precedence(top(opStack)) >= precedence(infix[i])))
            {
                prefix[j]=pop(&opStack);
                ++j;
            }
            push(&opStack, infix[i]);
        }
        else if(infix[i] == ')')
            push(&opStack, infix[i]);
        else if(infix[i] =='(')
        {
            while(top(opStack)!= ')')
            {
                prefix[j]=pop(&opStack);
                ++j;
            }
            pop(&opStack);
        }
        else
        {
            prefix[j]=infix[i];
            ++j;
        }
    }

    while(!(isEmpty(opStack)))
    {
        prefix[j] = pop(&opStack);
        ++j;
    }
    prefix[j] = '\0';
    strrev(prefix);
}
#endif // POSLISH_NOTATION_H_INCLUDED
