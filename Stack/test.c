/*
 * Tests the stack data structure implemented in stack.h
 * and stack.c
 */


#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main() {
    
    
    // initialize
    stack s;
    stack_init(&s);

    // push some values
    int a = 1, b = 2, c = 3, d = 5, e = 8;

    stack_push(&s, &a);
    stack_push(&s, &b);
    stack_push(&s, &c);
    stack_push(&s, &d);
    stack_push(&s, &e);
    
    // check size
    printf("Stack has %d elements\n", stack_size(&s));
    
    // pop them to check the order
    int* top;
    while(stack_size(&s) > 0){
        top = stack_pop(&s);
        printf("The top value is %d\n", *top);
    }
    
    stack_destroy(&s);
     
    
    return 0;
}
