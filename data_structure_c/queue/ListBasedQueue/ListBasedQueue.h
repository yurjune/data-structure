#ifndef LIST_BASED_QUEUE_H
#define LIST_BASED_QUEUE_H

typedef int Data;

typedef struct _Node {
  Data data;
  struct _Node *next;
} Node;

typedef struct {
  Node *front;
  Node *rear;
} Queue;

void QueueInit(Queue *queue);

int QIsEmpty(Queue *queue);

void Enqueue(Queue *queue, Data data);

Data Dequeue(Queue *queue);

Data Qpeek(Queue *queue);

#endif
