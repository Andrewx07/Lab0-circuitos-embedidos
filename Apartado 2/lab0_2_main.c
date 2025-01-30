#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "static_stack.c"
#include "dynamic_stack.c"
size_t counter = 0;
bool pin1 = false;
typedef enum instructions
{
    toggle = 0x00,
    print_pin1 = 0x01,
    raise_counter = 0x02,
    print_counter = 0x03,
    count_stacks = 0x05,
    check_full_pile = 0x06,

} interrupts;

int static_interruptions_handler(static_stack *stack)
{

    while (emptyStack_static(stack))
    {

        switch (pop_static(stack))
        {
        case toggle:
            printf("Toggle pin1 \n");
            pin1 = !pin1;
            break;
        case print_pin1:
            printf("Print pin1 %s \n", pin1 ? "true" : "false");
            break;
        case raise_counter:
            counter++;
            printf("raise one the counter \n");
            break;
        case print_counter:
            printf("Print Counter %d \n", counter);
            break;
        case count_stacks:
            printf("Number of static_stacks %d \n", count_static(stack));
            break;
        case check_full_pile:
            if (fullStack_static(stack))
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Stack is not full\n");
            }

            break;
        default:
            printf("Invalid Instruction\n");
            break;
        }
    }
    return 0;
}

int dynamic_interruptions_handler(dynamic_stack *stack)
{

    while (emptyStack_dynamic(stack))
    {

        switch (pop_dynamic(stack))
        {
        case toggle:
            printf("Toggle pin1 \n");
            pin1 = !pin1;
            break;
        case print_pin1:
            printf("Print pin1 %s \n", pin1 ? "true" : "false");
            break;
        case raise_counter:
            counter++;
            printf("raise one the counter \n");
            break;
        case print_counter:
            printf("Print Counter %d \n", counter);
            break;
        case count_stacks:
            printf("Number of dynamic_stacks %d \n", count_dynamic(stack));
            break;
        case check_full_pile:
            if (fullStack_dynamic(stack))
            {
                printf("Stack is full\n");
            }
            else
            {
                printf("Stack is not full\n");
            }

            break;
        default:
            printf("Invalid Instruction\n");
            break;
        }
    }
    return 0;
}

int main()
{
    static_stack statics;
    init_static(&statics);

    dynamic_stack dynamic;
    dynamic = *init_dynamic(12);

    uint8_t pin1_buffer[12] = {toggle, print_pin1, raise_counter, print_counter, 0x04, count_stacks, check_full_pile, toggle, toggle, toggle, check_full_pile};

    for (int i = 0; i < 12; i++)
    {
        push_static(&statics, pin1_buffer[i]);
    }
    for (int i = 0; i < 12; i++)
    {
        push_dynamic(&dynamic, pin1_buffer[i]);
    }
    printf("\nStatic Stack aplication\n");
    static_interruptions_handler(&statics);

    printf("\nDynamic Stack aplication\n");
    dynamic_interruptions_handler(&dynamic);

    return 0;
}
