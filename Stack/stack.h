#ifndef STACK_H_
#define STACK_H_

/**
 Stack Data Structure
 **/

typedef struct _stack{
    void** items; // dynamic array holding items in the stack
    int size;
    int capacity;
} stack;

void stack_init(stack* s);
void stack_push(stack* s, void* ptr);
void* stack_pop(stack* s);
void* stack_peek(stack* s);
int stack_size(stack* s);
void stack_resize(stack* s);
void stack_destroy(stack* s);

#endif