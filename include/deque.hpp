#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <memory>

template <typename T> struct Node {
    T item;
    std::shared_ptr<Node<T>> next;
    std::shared_ptr<Node<T>> prev;
    Node(T data) : item(data), next(nullptr), prev(nullptr) {}
};

/*

 Left(Head) <-------------> Right(Tail)
[Next Prev]<->[Next Prev]<->[Next Prev]

 */
template <typename T> class Deque {
  public:
    bool isEmpty() { return static_cast<bool>(N <= 0); }
    int size() { return N; }
    void pushLeft(T item);
    void pushRight(T item);
    T popLeft() {}
    T popRight() {}
    T peekLeft();
    T peekRight();

  private:
    std::shared_ptr<Node<T>> left = nullptr;
    std::shared_ptr<Node<T>> right = nullptr;
    int N = 0; // queue size
};

#include "deque.ipp"

#endif
