#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

template <typename T> class Deque {
  public:
    void Print();
    Deque() {}
    bool isEmpty() { return false; }
    int size() { return 0; }
    void pushLeft(T item) {}
    void pushRight(T item) {}
    T popLeft() {}
    T popRight() {}
};

#include "deque.ipp"

#endif
