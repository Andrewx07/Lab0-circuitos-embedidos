#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 12;



typedef struct ITEM_dynamic
{
    uint8_t pin1;
    uint32_t time;
    uint8_t* reference;

} item_dynamic;

typedef struct DYNAMIC_STACK
{
    uint8_t *data;
    int8_t top;
    uint8_t size;

} dynamic_stack;

int count_dynamic(dynamic_stack *stack)
{
    printf("count_dynamic: %d\n", stack->top + 1 );
    return stack->top + 1;
}

int fullStack_dynamic(dynamic_stack *stack)
{
    if (stack->top == stack->size-1)
    {

        return 1;
    }
    else
    {
        return 0;
    }
}

int emptyStack_dynamic(dynamic_stack *stack)
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

dynamic_stack *init_dynamic(uint8_t size)
{
    dynamic_stack *stack = (dynamic_stack *)malloc(sizeof(dynamic_stack));
    if (stack == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    stack->data = (uint8_t *)malloc(sizeof(uint8_t) * size);
    if (stack->data == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    stack->top = -1;
    stack->size = size;
    return stack;
}

void push_dynamic(dynamic_stack *stack, uint8_t value)
{
    if (fullStack_dynamic(stack) == 0)
    {
        stack->top++;
        stack->data[stack->top] = value;
    
    }
    else
    {
       
    }
}

int pop_dynamic(dynamic_stack *stack)
{
    if (stack->top == -1)
    {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top--];
}

