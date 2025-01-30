#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#define MAX_STACK 12



typedef struct ITEM_static 
{
    uint8_t pin1;
    uint32_t time;
    uint8_t* reference;
} item_static;


typedef struct STATIC_STACK
{
    uint8_t stack[MAX_STACK];
    int8_t top;

} static_stack;





int count_static(static_stack *stack)
{   
   //printf("Counter: %d\n", stack->top + 1);
    return stack->top + 1;
}

int fullStack_static(static_stack *stack)
{
    if (stack->top == MAX_STACK)
    {
        ;
        return 1;
    }
    else
    {
        return 0;
    }
}

int emptyStack_static(static_stack *stack)
{
    if (stack->top == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void init_static(static_stack *stack)
{
    stack->top = -1;
}

int push_static(static_stack *stack, uint8_t value)
{
    if (fullStack_static(stack) == 0)
    {
        stack->top++;
        stack->stack[stack->top] = value;
        return 0;
    }
    else
    {
        return -1;
    }
}

int pop_static(static_stack *stack)
{
    if (emptyStack_static(stack) == 1)
    {
        int value = stack->stack[stack->top];
        stack->top--;
        return value;
    }
    else
    {
        printf("Stack is empty cannot be pop\n");
        return -1;
    }
}


