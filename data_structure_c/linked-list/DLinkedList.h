#ifndef D_LINKED_LIST_H
#define D_LINKED_LIST_H

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node {
  LData data;
  struct _node *next;
} Node;

typedef struct {
  Node *head;
  Node *before;
  Node *cur;
  int numOfData;
  int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));

#endif
