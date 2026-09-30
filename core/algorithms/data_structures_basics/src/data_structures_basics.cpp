#include "data_structures_basics.h"

namespace data_structures_basics {

Node::Node(int) {}

int Node::get_value() const {
    return -1;
}

Node* Node::get_next() const {
    return nullptr;
}

void Node::set_next(Node*) {}

LinkedList::LinkedList() {}

LinkedList::~LinkedList() {}

int LinkedList::get_head() const {
    return -1;
}

void LinkedList::insert_head(int) {}

void LinkedList::insert_tail(int) {}

int LinkedList::delete_value(int) {
    return -1;
}

bool LinkedList::is_empty() const {
    return false;
}

std::size_t LinkedList::size() const {
    return 0;
}

Stack::Stack() {}

Stack::~Stack() {}

void Stack::push(int) {}

int Stack::pop() {
    return -1;
}

int Stack::peek() const {
    return -1;
}

bool Stack::is_empty() const {
    return false;
}

std::size_t Stack::size() const {
    return 0;
}

Queue::Queue() {}

Queue::~Queue() {}

void Queue::enqueue(int) {}

int Queue::dequeue() {
    return -1;
}

int Queue::peek() const {
    return -1;
}

bool Queue::is_empty() const {
    return false;
}

std::size_t Queue::size() const {
    return 0;
}

} // namespace data_structures_basics
