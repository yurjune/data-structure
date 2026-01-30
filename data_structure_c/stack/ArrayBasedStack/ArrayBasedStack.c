#include "ArrayBasedStack.h"
#include <stdlib.h>

void StackInit(Stack *stack) { stack->top = -1; }

int SIsEmpty(Stack *stack) { return stack->top == -1; }

void SPush(Stack *stack, SData data) {
  if (stack->top >= STACK_LEN - 1) {
    exit(-1);
  }

  stack->top++;
  stack->data[stack->top] = data;
}

int SPop(Stack *stack) {
  int pIdx;

  if (SIsEmpty(stack)) {
    exit(-1);
  }

  pIdx = stack->top;
  stack->top -= 1;
  return stack->data[pIdx];
}

int SPeek(Stack *stack) {
  if (SIsEmpty(stack)) {
    exit(-1);
  }

  return stack->data[stack->top];
}
