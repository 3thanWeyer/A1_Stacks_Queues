#include "sqll.h"
#include <iostream>

void push(node *&head, int value) {
  node *newNode = new node;
  newNode->data = value;
  newNode->next = nullptr;

  // INSERT AT INDEX 0
  newNode->next = head;
  head = newNode;
}

void pop(node *&head) {
  if (head == nullptr) {
    cout << "Stack is empty, nothing to pop" << endl;
    return;
  }

  // remove the head
  node *dltTemp = head;
  head = head->next;

  delete dltTemp;
}

void enqueue(node *&head, int value) {
  node *newNode = new node;
  newNode->data = value;
  newNode->next = nullptr;

  if (head == nullptr) {
    head = newNode;
  } else {
    node *tempNode = head;
    while (tempNode->next != nullptr) {
      tempNode = tempNode->next;
    }
    tempNode->next = newNode;
  }
}

void dequeue(node *&head) {
  node *tempNode = head;

  if (head == nullptr) {
    cout << "List is empty!" << endl;
    return;
  } else {
    head = tempNode->next;
    delete tempNode;
    return;
  }
}

void displayList(node *head) {
  node *walker = head;

  while (walker != nullptr) {
    cout << walker->data << " ";
    walker = walker->next;
  }
  cout << endl;
}
