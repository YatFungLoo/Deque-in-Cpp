#ifndef DEQUE_IPP
#define DEQUE_IPP

#include "deque.hpp"
#include <stdexcept>

template <typename T> void Deque<T>::pushLeft(T item) {
    auto node = std::make_shared<Node<T>>(item);
    if (left == nullptr) {
        left = right = node;
    } else {
        node->prev = left; // new node's prev points to old head
        left->next = node; // old head next points to new node
        left = node; // new node is the new head, all ptr defaults to nullptr
    }
    N++;
}

template <typename T> void Deque<T>::pushRight(T item) {
    auto node = std::make_shared<Node<T>>(item);
    if (right == nullptr) {
        left = right = node;
    } else {
        node->next = right; // new node's next points to old head
        right->prev = node; // old head next points to new node
        right = node; // new node is the new head, all ptr defaults to nullptr
    }
    N++;
}

template <typename T> T Deque<T>::peekLeft() {
    if (left == nullptr) {
        throw std::out_of_range("Deque is empty");
    }
    return left->item;
}

template <typename T> T Deque<T>::peekRight() {
    if (left == nullptr) {
        throw std::out_of_range("Deque is empty");
    }
    return right->item;
}
#endif
