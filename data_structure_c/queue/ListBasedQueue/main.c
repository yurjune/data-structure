#include "ListBasedQueue.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Queue queue;
  Data data;

  QueueInit(&queue);

  Enqueue(&queue, 1);
  Enqueue(&queue, 2);
  Enqueue(&queue, 3);
  Enqueue(&queue, 4);
  Enqueue(&queue, 5);

  printf("%d\n", Dequeue(&queue));
  printf("%d\n", Dequeue(&queue));
  printf("%d\n", Dequeue(&queue));
  printf("%d\n", Dequeue(&queue));
  printf("%d\n", Dequeue(&queue));

  return 0;
}
