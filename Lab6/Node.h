#pragma once

template<class T>

class Node {
public:
    T data;
    Node<T>* next;

    Node(T value, Node<T>* node = NULL) {
        data = value;
        next = node;
    };

    T getData() {
        return data;
    };

    void setData(T val) {
        data = val;
    };

    Node<T>* getNext() {
        return next;
    };

    void setNext(Node<T>* node) {
        next = node;
    };
};