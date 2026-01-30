#include "ListBasedStack.h"
#include <stdlib.h>

void StackInit(Stack *stack) { stack->head = NULL; }

int SIsEmpty(Stack *stack) { return stack->head == NULL; }

void SPush(Stack *stack, SData data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->next = stack->head;
  node->data = data;
  stack->head = node;
}

int SPop(Stack *stack) {
  if (SIsEmpty(stack)) {
    exit(-1);
  }

  int res;
  Node *rnode = stack->head;
  res = rnode->data;
  stack->head = stack->head->next;

  free(rnode);

  return res;
}

int SPeek(Stack *stack) {
  if (SIsEmpty(stack)) {
    exit(-1);
  }

  return stack->head->data;
}
