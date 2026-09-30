#ifndef DATA_STRUCTURES_BASICS_H
#define DATA_STRUCTURES_BASICS_H

#include <cstddef>

namespace data_structures_basics {

constexpr int FAILURE_VALUE = -1;

class Node {
public:
    explicit Node(int value);
    int get_value() const;
    Node* get_next() const;
    void set_next(Node* next);

private:
    int value_;
    Node* next_;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    bool is_empty() const;
    std::size_t size() const;
    int get_head() const;
    void insert_head(int value);
    void insert_tail(int value);
    bool delete_value(int value);

private:
    Node* head_;
    Node* tail_;
    std::size_t count_;
};

class Stack {
public:
    Stack();
    ~Stack();
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    bool is_empty() const;
    std::size_t size() const;
    void push(int value);
    int pop();
    int peek() const;

private:
    Node* top_;
    std::size_t count_;
};

class Queue {
public:
    Queue();
    ~Queue();
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    bool is_empty() const;
    std::size_t size() const;
    void enqueue(int value);
    int dequeue();
    int peek() const;

private:
    Node* front_;
    Node* rear_;
    std::size_t count_;
};

} // namespace data_structures_basics

#endif // DATA_STRUCTURES_BASICS_H
