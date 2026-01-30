#include "ListBasedQueue.h"
#include <stdio.h>
#include <stdlib.h>

void QueueInit(Queue *queue) {
  queue->front = NULL;
  queue->rear = NULL;
}

int QIsEmpty(Queue *queue) {
  return queue->front == NULL;
}

void Enqueue(Queue *queue, Data data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->next = NULL;
  node->data = data;

  if (QIsEmpty(queue)) {
    queue->front = node;
    queue->rear = node;
  } else {
    queue->rear->next = node;
    queue->rear = node;
  }
}

Data Dequeue(Queue *queue) {
  if (QIsEmpty(queue)) {
    exit(-1);
  }

  Node *rNode = queue->front;
  Data rData = queue->front->data;
  queue->front = queue->front->next;

  if (queue->front == NULL) {
    queue->rear = NULL;
  }

  free(rNode);

  return rData;
}

Data Qpeek(Queue *queue) {
  if (QIsEmpty(queue)) {
    exit(-1);
  }

  return queue->front->data;
}
