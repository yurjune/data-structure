#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

typedef int Val;

typedef struct _Node {
  Val val;
  struct _Node *next;
  struct _Node *prev;
} Node;

typedef struct {
  int size;
  Node *head;
  Node *tail;
} DoublyLinkedList;

typedef DoublyLinkedList List;

Node *NodeInit(Val val);
void ListInit(List *list);

int LEmpty(List *list);
int LSize(List *list);

Val LFront(List *list);
Val LRear(List *list);

void LInsertFront(List *list, Val val);
void LInsertRear(List *list, Val val);

Val LPopFront(List *list);
Val LPopRear(List *list);

void LTraverse(List *list);
void LTraverseReverse(List *list);

#endif
