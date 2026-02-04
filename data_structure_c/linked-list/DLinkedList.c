#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

Node *NodeInit(Val val) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->val = val;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

void ListInit(List *list) {
  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
}

int LEmpty(List *list) {
  return list->size == 0;
}

int LSize(List *list) {
  return list->size;
}

Val LFront(List *list) {
  if (LEmpty(list)) {
    exit(-1);
  }
  return list->head->val;
}

Val LRear(List *list) {
  if (LEmpty(list)) {
    exit(-1);
  }
  return list->tail->val;
}

void LInsertFront(List *list, Val val) {
  Node *node = NodeInit(val);

  if (LEmpty(list)) {
    list->head = node;
    list->tail = node;
  } else {
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
  }
  list->size += 1;
}

void LInsertRear(List *list, Val val) {
  Node *node = NodeInit(val);

  if (LEmpty(list)) {
    list->head = node;
    list->tail = node;
  } else {
    node->prev = list->tail;
    list->tail->next = node;
    list->tail = node;
  }
  list->size += 1;
}

Val LPopFront(List *list) {
  if (LEmpty(list)) {
    exit(-1);
  }

  list->size -= 1;
  Node *head = list->head;
  Val val = head->val;
  list->head = head->next;
  if (list->head == NULL) {
    list->tail = NULL;
  } else {
    list->head->prev = NULL;
  }
  free(head);
  return val;
}

Val LPopRear(List *list) {
  if (LEmpty(list)) {
    exit(-1);
  }

  list->size -= 1;
  Node *tail = list->tail;
  Val val = tail->val;
  list->tail = tail->prev;
  if (list->tail == NULL) {
    list->head = NULL;
  } else {
    list->tail->next = NULL;
  }
  return val;
}

void LTraverse(List *list) {
  if (LEmpty(list)) {
    return;
  }

  Node *current = list->head;
  while (current != NULL) {
    printf("%d -> ", current->val);
    current = current->next;
  }
  printf("\n");
}

void LTraverseReverse(List *list) {
  if (LEmpty(list)) {
    return;
  }

  Node *current = list->tail;
  while (current != NULL) {
    printf("%d -> ", current->val);
    current = current->prev;
  }
  printf("\n");
}
