#ifndef LIST_BASED_STACK_H
#define LIST_BASED_STACK_H

typedef struct _node {
  int data;
  struct _node *next;
} Node;

typedef struct {
  Node *head;
} Stack;

typedef int SData;

void StackInit(Stack *stack);

int SIsEmpty(Stack *stack);

void SPush(Stack *stack, SData data);

int SPop(Stack *stack);

int SPeek(Stack *stack);

#endif
