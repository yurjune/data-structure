#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List *plist) {
  plist->head = (Node *)malloc(sizeof(Node));
  plist->before = NULL;
  plist->cur = NULL;
  plist->numOfData = 0;
  plist->comp = NULL;
}

void FInsert(List *plist, LData data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = plist->head->next;

  plist->head->next = node;
  plist->numOfData++;
}

void SInsert(List *plist, LData data) {
  Node *node = (Node *)malloc(sizeof(Node));
  Node *pred = plist->head;
  node->data = data;

  while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
    pred = pred->next;
  }

  node->next = pred->next;
  pred->next = node;
  plist->numOfData++;
}

void LInsert(List *plist, LData data) {
  if (plist->comp != NULL) {
    SInsert(plist, data);
  } else {
    FInsert(plist, data);
  }
}

int LFirst(List *plist, LData *pdata) {
  if (plist->head->next == NULL) {
    return FALSE;
  }

  plist->before = plist->head;
  plist->cur = plist->head->next;
  *pdata = plist->cur->data;

  return TRUE;
}

int LNext(List *plist, LData *pdata) {
  if (plist->cur->next == NULL) {
    return FALSE;
  }

  plist->before = plist->cur;
  plist->cur = plist->cur->next;
  *pdata = plist->cur->data;
  return TRUE;
}

LData LRemove(List *plist) {
  Node *rpos = plist->cur;
  LData rdata = rpos->data;

  plist->before->next = rpos->next;
  plist->cur = plist->before;
  plist->numOfData--;

  free(rpos);

  return rdata;
}

int LCount(List *plist) {
  return plist->numOfData;
}

void SetSortRule(List *plist, int (*comp)(LData, LData)) {
  plist->comp = comp;
}
