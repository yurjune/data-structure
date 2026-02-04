#include "DLinkedList.h"
#include <stdio.h>

int main(void) {
  List list;

  ListInit(&list);
  printf("Empty: %d\n", LEmpty(&list));
  printf("Size: %d\n", LSize(&list));

  LInsertFront(&list, 6);
  LInsertFront(&list, 5);
  LInsertFront(&list, 4);
  LInsertFront(&list, 3);
  LInsertFront(&list, 2);
  LInsertFront(&list, 1);

  printf("Front: %d\n", LFront(&list));
  printf("Rear: %d\n", LRear(&list));
  printf("Traverse:\n");
  LTraverse(&list);
  printf("Traverse Reverse:\n");
  LTraverseReverse(&list);

  printf("Pop Front: %d\n", LPopFront(&list));
  printf("Pop Rear: %d\n", LPopRear(&list));
  printf("Traverse:\n");
  LTraverse(&list);
}
