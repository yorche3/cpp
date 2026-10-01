#include "data_structures_basics.h"

namespace data_structures_basics {

Node::Node(int value):
    value_(value),
    next_(nullptr)
{}

int Node::get_value() const {
    return value_;
}

Node* Node::get_next() const {
    return next_;
}

void Node::set_next(Node* next) {
    next_ = next;
}

LinkedList::LinkedList():
    head_(nullptr),
    tail_(nullptr),
    count_(0)
{}

LinkedList::~LinkedList() {
    Node* current = head_;
    while (current != nullptr) {
        Node* temp = current;
        current = current->get_next();
        delete temp;
    }
    head_ = nullptr;
    tail_ = nullptr;
    count_ = 0;
}

bool LinkedList::is_empty() const {
    return count_ == 0;
}

std::size_t LinkedList::size() const {
    return count_;
}

int LinkedList::get_head() const {
    if (is_empty()) {
        return FAILURE_VALUE;
    }
    return head_->get_value();
}

void LinkedList::insert_head(int value) {
    Node* new_node = new Node(value);
    new_node->set_next(head_);
    head_ = new_node;
    if (tail_ == nullptr) {
        tail_ = new_node;
    }
    ++count_;
}

void LinkedList::insert_tail(int value) {
    Node* new_node = new Node(value);
    if (tail_ != nullptr) {
        tail_->set_next(new_node);
    }
    tail_ = new_node;
    if (head_ == nullptr) {
        head_ = new_node;
    }
    ++count_;
}

bool LinkedList::delete_value(int value) {
    Node* current = head_;
    Node* previous = nullptr;
    while (current != nullptr) {
        if (current->get_value() == value) {
            if (previous != nullptr) {
                previous->set_next(current->get_next());
            } else {
                head_ = current->get_next();
            }
            if (current == tail_) {
                tail_ = previous;
            }
            delete current;
            --count_;
            return true;
        }
        previous = current;
        current = current->get_next();
    }
    return false;
}

Stack::Stack():
    top_(nullptr),
    count_(0)
{}

Stack::~Stack() {
    Node* current = top_;
    while (current != nullptr) {
        Node* temp = current;
        current = current->get_next();
        delete temp;
    }
    top_ = nullptr;
    count_ = 0;
}

bool Stack::is_empty() const {
    return count_ == 0;
}

std::size_t Stack::size() const {
    return count_;
}

void Stack::push(int value) {
    Node* new_node = new Node(value);
    new_node->set_next(top_);
    top_ = new_node;
    ++count_;
}

int Stack::peek() const {
    if (is_empty()) {
        return FAILURE_VALUE;
    }
    return top_->get_value();
}

int Stack::pop() {
    if (is_empty()) {
        return FAILURE_VALUE;
    }
    Node* temp = top_;
    int value = temp->get_value();
    top_ = top_->get_next();
    delete temp;
    --count_;
    return value;
}

Queue::Queue():
    front_(nullptr),
    rear_(nullptr),
    count_(0)
{}

Queue::~Queue() {
    Node* current = front_;
    while (current != nullptr) {
        Node* temp = current;
        current = current->get_next();
        delete temp;
    }
    front_ = nullptr;
    rear_ = nullptr;
    count_ = 0;
}

bool Queue::is_empty() const {
    return count_ == 0;
}

std::size_t Queue::size() const {
    return count_;
}

void Queue::enqueue(int value) {
    Node* new_node = new Node(value);
    if (rear_ != nullptr) {
        rear_->set_next(new_node);
    }
    rear_ = new_node;
    if (front_ == nullptr) {
        front_ = new_node;
    }
    ++count_;
}

int Queue::peek() const {
    if (is_empty()) {
        return FAILURE_VALUE;
    }
    return front_->get_value();
}

int Queue::dequeue() {
    if (is_empty()) {
        return FAILURE_VALUE;
    }
    Node* temp = front_;
    int value = temp->get_value();
    front_ = front_->get_next();
    if (front_ == nullptr) {
        rear_ = nullptr;
    }
    delete temp;
    --count_;
    return value;
}

} // namespace data_structures_basics
