#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#define QUEUE_LEN 100

typedef struct {
  int data[QUEUE_LEN];
  int front;
  int rear;
} Queue;

typedef int Data;

void QueueInit(Queue *queue);

int QIsFull(Queue *queue);

int QIsEmpty(Queue *queue);

int NextIdx(int idx);

void Enqueue(Queue *queue, Data data);

Data Dequeue(Queue *queue);

Data Qpeek(Queue *queue);

#endif
