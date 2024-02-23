// LinkedQueue.h

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <iostream>

template <typename T>
class LinkedQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    size_t size;

public:
    LinkedQueue() : front(nullptr), rear(nullptr), size(0) {}

    ~LinkedQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(T data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty. Cannot dequeue.");
        }
        Node* temp = front;
        T data = front->data;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
        size--;
        return data;
    }

    T peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty. Cannot peek.");
        }
        return front->data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }
};

#endif // LINKED_QUEUE_H

