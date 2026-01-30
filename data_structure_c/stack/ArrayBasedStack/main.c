#include "ArrayBasedStack.h"
#include <stdio.h>

int main() {
  Stack stack;
  int data;

  StackInit(&stack);
  SPush(&stack, 1);
  SPush(&stack, 2);
  SPush(&stack, 3);
  SPush(&stack, 4);
  SPush(&stack, 5);

  printf("peek: %d\n", SPeek(&stack));

  while (!SIsEmpty(&stack)) {
    printf("pop: %d\n", SPop(&stack));
  }

  return 0;
}
