#include "data_structures_advanced.h"

namespace data_structures_advanced {

Node::Node(int):
    value_(0)
{}

int Node::get_value() const {
    return -1;
}

TreeNode::TreeNode(int value):
    Node(value),
    left_(nullptr),
    right_(nullptr)
{}

TreeNode* TreeNode::get_left() const {
    return nullptr;
}

TreeNode* TreeNode::get_right() const {
    return nullptr;
}

void TreeNode::set_left(TreeNode*) {}

void TreeNode::set_right(TreeNode*) {}

BinaryTree::BinaryTree():
    root_(nullptr),
    count_(0)
{}

BinaryTree::~BinaryTree() {}

bool BinaryTree::insert(int) {
    return false;
}

bool BinaryTree::contains(int) const {
    return false;
}

bool BinaryTree::is_empty() const {
    return false;
}

std::size_t BinaryTree::size() const {
    return 0;
}

GraphNode::GraphNode(int label):
    Node(label),
    next_vertex_(nullptr)
{}

Graph::Graph():
    vertices_(nullptr),
    vertex_total_(0),
    edges_(0)
{}

Graph::~Graph() {}

bool Graph::add_vertex(int) {
    return false;
}

bool Graph::add_edge(int, int) {
    return false;
}

bool Graph::has_edge(int, int) const {
    return false;
}

std::unique_ptr<std::list<int>> Graph::get_neighbors(int) const {
    return nullptr;
}

bool Graph::is_empty() const {
    return false;
}

std::size_t Graph::vertex_count() const {
    return 0;
}

std::size_t Graph::edge_count() const {
    return 0;
}

} // namespace data_structures_advanced
