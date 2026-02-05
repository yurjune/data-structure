#include "doubly-linked-list.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>

bool DLinkedList::empty() {
  return size == 0;
}

int DLinkedList::len() {
  return size;
}

Val DLinkedList::front() {
  if (empty()) {
    throw std::out_of_range("Empty list");
  }

  return head->val;
}

Val DLinkedList::rear() {
  if (empty()) {
    throw std::out_of_range("Empty list");
  }

  return tail->val;
}

void DLinkedList::insert_front(Val val) {
  auto node = std::make_shared<Node>(val);
  if (empty()) {
    head = node;
    tail = node;
  } else {
    node->next = head;
    head->prev = node;
    head = node;
  }
  size += 1;
}

void DLinkedList::insert_rear(Val val) {
  auto node = std::make_shared<Node>(val);
  if (empty()) {
    head = node;
    tail = node;
  } else {
    tail->next = node;
    node->prev = tail;
    tail = node;
  }
  size += 1;
}

Val DLinkedList::pop_front() {
  if (empty()) {
    throw std::out_of_range("out of range");
  }

  size -= 1;
  Val val = head->val;
  if (head->next != nullptr) {
    head->next->prev.reset();
    head = head->next;
  } else {
    head = nullptr;
    tail = nullptr;
  }

  return val;
}

Val DLinkedList::pop_rear() {
  if (empty()) {
    throw std::out_of_range("out of range");
  }

  size -= 1;
  Val val = tail->val;
  if (!tail->prev.expired()) {
    shared_ptr<Node> temp = tail->prev.lock();
    temp->next = nullptr;
    tail = temp;
  } else {
    head = nullptr;
    tail = nullptr;
  }

  return val;
}

void DLinkedList::traverse() {
  if (empty())
    return;

  shared_ptr<Node> current = head;
  while (current != nullptr) {
    std::cout << current->val << " -> ";
    current = current->next;
  }
  std::cout << std::endl;
}

void DLinkedList::traverse_reverse() {
  if (empty())
    return;

  shared_ptr<Node> current = tail;
  while (current != nullptr) {
    std::cout << current->val << " -> ";
    current = current->prev.lock();
  }
  std::cout << std::endl;
}
