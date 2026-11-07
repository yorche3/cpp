#include "data_structures_advanced.h"

namespace data_structures_advanced {

namespace {

void free_tree(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    free_tree(node->get_left());
    free_tree(node->get_right());
    delete node;
}

} // namespace

Node::Node(int value):
    value_(value)
{}

int Node::get_value() const {
    return value_;
}

TreeNode::TreeNode(int value):
    Node(value),
    left_(nullptr),
    right_(nullptr)
{}

TreeNode* TreeNode::get_left() const {
    return left_;
}

TreeNode* TreeNode::get_right() const {
    return right_;
}

void TreeNode::set_left(TreeNode* node) {
    left_ = node;
}

void TreeNode::set_right(TreeNode* node) {
    right_ = node;
}

BinaryTree::BinaryTree():
    root_(nullptr),
    count_(0)
{}

BinaryTree::~BinaryTree() {
    free_tree(root_);
    root_ = nullptr;
    count_ = 0;
}

bool BinaryTree::insert(int value) {
    if (root_ == nullptr) {
        root_ = new TreeNode(value);
        ++count_;
        return true;
    }
    TreeNode* current = root_;
    while (true) {
        if (value == current->get_value()) {
            // Idempotente: no crece el arbol.
            return true;
        } else if (value < current->get_value()) {
            if (current->get_left() == nullptr) {
                current->set_left(new TreeNode(value));
                count_++;
                return true;
            }
            current = current->get_left();
        } else {
            if (current->get_right() == nullptr) {
                current->set_right(new TreeNode(value));
                count_++;
                return true;
            }
            current = current->get_right();
        }
    }
}

bool BinaryTree::contains(int value) const {
    const TreeNode* current = root_;
    while (current != nullptr) {
        if (value == current->get_value()) {
            return true;
        } else if (value < current->get_value()) {
            current = current->get_left();
        } else {
            current = current->get_right();
        }
    }
    return false;
}

bool BinaryTree::is_empty() const {
    return count_ == 0;
}

std::size_t BinaryTree::size() const {
    return count_;
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

Graph::~Graph() {
    GraphNode* current = vertices_;
    while (current != nullptr) {
        GraphNode* next = current->next_vertex_;
        delete current;
        current = next;
    }
    vertices_ = nullptr;
    vertex_total_ = 0;
    edges_ = 0;
}

GraphNode* Graph::find_vertex(int label) {
    return const_cast<GraphNode*>(
        static_cast<const Graph*>(this)->find_vertex(label));
}

const GraphNode* Graph::find_vertex(int label) const {
    const GraphNode* current = vertices_;
    while (current != nullptr) {
        if (current->get_value() == label) {
            return current;
        }
        current = current->next_vertex_;
    }
    return nullptr;
}

bool Graph::add_vertex(int label) {
    if (find_vertex(label) != nullptr) {
        return true;
    }
    GraphNode* new_vertex = new GraphNode(label);
    new_vertex->next_vertex_ = vertices_;
    vertices_ = new_vertex;
    vertex_total_++;
    return true;
}

bool Graph::add_edge(int u, int v) {
    GraphNode* vertex_u = find_vertex(u);
    // Fallo sin efectos: ambos extremos deben existir.
    if (vertex_u == nullptr || find_vertex(v) == nullptr) {
        return false;
    }
    auto position = vertex_u->neighbors_.begin();
    while (position != vertex_u->neighbors_.end() && *position < v) {
        ++position;
    }
    if (position != vertex_u->neighbors_.end() && *position == v) {
        return true;
    }
    vertex_u->neighbors_.insert(position, v);
    ++edges_;
    return true;
}

bool Graph::has_edge(int u, int v) const {
    const GraphNode* vertex_u = find_vertex(u);
    if (vertex_u == nullptr) {
        return false;
    }
    for (int neighbor : vertex_u->neighbors_) {
        if (neighbor == v) {
            return true;
        }
    }
    return false;
}

std::unique_ptr<std::list<int>> Graph::get_neighbors(int u) const {
    const GraphNode* source = find_vertex(u);
    if (source == nullptr) {
        return nullptr;
    }
    return std::make_unique<std::list<int>>(source->neighbors_);
}

bool Graph::is_empty() const {
    return vertex_total_ == 0;
}

std::size_t Graph::vertex_count() const {
    return vertex_total_;
}

std::size_t Graph::edge_count() const {
    return edges_;
}

} // namespace data_structures_advanced
