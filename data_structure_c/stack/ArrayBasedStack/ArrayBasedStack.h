#ifndef ARRAY_BASED_STACK_H
#define ARRAY_BASED_STACK_H

#define STACK_LEN 100

typedef struct _Stack {
  int data[STACK_LEN];
  int top;
} Stack;

typedef int SData;

void StackInit(Stack *stack);

int SIsEmpty(Stack *stack);

void SPush(Stack *stack, SData data);

int SPop(Stack *stack);

int SPeek(Stack *stack);

#endif
