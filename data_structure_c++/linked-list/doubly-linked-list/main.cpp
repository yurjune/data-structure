#include "doubly-linked-list.hpp"
#include <iostream>

int main(void) {
  DLinkedList list;

  std::cout << "Empty: " << list.empty() << std::endl;
  std::cout << "Size: " << list.len() << std::endl;

  list.insert_rear(4);
  list.insert_rear(5);
  list.insert_rear(6);
  list.insert_front(3);
  list.insert_front(2);
  list.insert_front(1);

  std::cout << "Front: " << list.front() << std::endl;
  std::cout << "Rear: " << list.rear() << std::endl;

  std::cout << "Traverse: ";
  list.traverse();
  std::cout << "Traverse Reverse: ";
  list.traverse_reverse();

  std::cout << "Pop front: " << list.pop_front() << std::endl;
  std::cout << "Pop rear: " << list.pop_rear() << std::endl;
  std::cout << "Traverse: ";
  list.traverse();
}
