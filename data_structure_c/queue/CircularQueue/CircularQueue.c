#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>

void QueueInit(Queue *queue) {
  // (front+1) % queue_len 이 다음 deque target이 되도록 구현
  queue->front = 0;
  queue->rear = 0;
}

int QIsFull(Queue *queue) {
  return NextIdx(queue->rear) == queue->front;
}

int QIsEmpty(Queue *queue) {
  return queue->rear == queue->front;
}

int NextIdx(int idx) {
  return (idx + 1) % QUEUE_LEN;
}

void Enqueue(Queue *queue, Data data) {
  if (QIsFull(queue)) {
    exit(-1);
  }

  queue->rear = NextIdx(queue->rear);
  queue->data[queue->rear] = data;
}

Data Dequeue(Queue *queue) {
  if (QIsEmpty(queue)) {
    exit(-1);
  }

  queue->front = NextIdx(queue->front);
  return queue->data[queue->front];
}

Data Qpeek(Queue *queue) {
  if (QIsEmpty(queue)) {
    exit(-1);
  }

  return queue->data[NextIdx(queue->front)];
}
