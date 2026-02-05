#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <memory>

using std::shared_ptr;
using std::weak_ptr;

typedef int Val;

class DLinkedList {
private:
  struct Node {
    Val val;
    shared_ptr<Node> next;
    weak_ptr<Node> prev;

    Node(Val val) : val(val), next(nullptr), prev() {
    }
  };

  int size;
  shared_ptr<Node> head;
  shared_ptr<Node> tail;

public:
  bool empty();
  int len();

  Val front();
  Val rear();

  void insert_front(Val val);
  void insert_rear(Val val);

  Val pop_front();
  Val pop_rear();

  void traverse();
  void traverse_reverse();

  DLinkedList() : size(0), head(nullptr), tail(nullptr) {};
};

#endif
