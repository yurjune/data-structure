#include "DLinkedList.h"
#include <stdio.h>

int ascending(LData d1, LData d2) {
  return d1 > d2;
}

int main(void) {
  List list;
  int data;

  ListInit(&list);

  SetSortRule(&list, ascending);

  LInsert(&list, 30);
  LInsert(&list, 20);
  LInsert(&list, 10);
  LInsert(&list, 20);
  LInsert(&list, 30);

  // 순회
  printf("현재 데이터 수: %d\n", LCount(&list));
  if (LFirst(&list, &data)) {
    printf("데이터: %d\n", data);

    while (LNext(&list, &data)) {
      printf("데이터: %d\n", data);
    }
  }

  // 제거
  if (LFirst(&list, &data)) {
    if (data == 20) {
      LRemove(&list);
    }

    while (LNext(&list, &data)) {
      if (data == 20) {
        LRemove(&list);
      }
    }
  }

  LInsert(&list, 15);

  // 순회
  printf("현재 데이터 수: %d\n", LCount(&list));
  if (LFirst(&list, &data)) {
    printf("데이터: %d\n", data);

    while (LNext(&list, &data)) {
      printf("데이터: %d\n", data);
    }
  }
}
