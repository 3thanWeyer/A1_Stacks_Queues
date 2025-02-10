#include "sqdll.h"
#include <iostream>

void enqueueFront(node *&head, node *&tail, int value) {
  // Create the node to be inserted at the front
  node *newNode = new node;
  newNode->data = value;
  newNode->next = head;
  newNode->prev = nullptr;

  if (head == nullptr) {
    head = tail = newNode;
  } else {
    head->prev = newNode;
    head = newNode;
  }
}

void enqueueBack(node *&head, node *&tail, int value) {
  node *newNode = new node;
  newNode->data = value;
  newNode->next = nullptr;
  newNode->prev = tail;

  if (head == nullptr) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void dequeueFront(node *&head, node *&tail) {
  if (head == nullptr) {
    cout << "List is empty" << endl;
  } else if (head == tail) { // deal with removing one node correctly
    delete tail;
    head = nullptr;
    tail = nullptr;
  } else {
    node *tNode = head;
    head = head->next;
    head->prev = nullptr;
    delete tNode;
  }
}

void dequeueBack(node *&head, node *&tail) {
  if (head == nullptr) {
    cout << "List is empty!" << endl;
  } else if (head == tail) {
    delete tail;
    head = nullptr;
    tail = nullptr;
  } else {
    node *tNode = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete tNode;
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
