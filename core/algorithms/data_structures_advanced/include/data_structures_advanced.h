#ifndef DATA_STRUCTURES_ADVANCED_H
#define DATA_STRUCTURES_ADVANCED_H

#include <cstddef>
#include <list>
#include <memory>

namespace data_structures_advanced {

class Node {
public:
    [[nodiscard]] int get_value() const;

protected:
    explicit Node(int value);
    // Protegido y no virtual: no se borra por Node* (C.35).
    ~Node() = default;

private:
    int value_;
};

class TreeNode final : public Node {
public:
    explicit TreeNode(int value);
    [[nodiscard]] TreeNode* get_left() const;
    [[nodiscard]] TreeNode* get_right() const;
    void set_left(TreeNode* node);
    void set_right(TreeNode* node);

private:
    TreeNode* left_;
    TreeNode* right_;
};

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();
    BinaryTree(const BinaryTree&) = delete;
    BinaryTree& operator=(const BinaryTree&) = delete;
    BinaryTree(BinaryTree&&) = delete;
    BinaryTree& operator=(BinaryTree&&) = delete;

    [[nodiscard]] bool insert(int value);
    [[nodiscard]] bool contains(int value) const;
    [[nodiscard]] bool is_empty() const;
    [[nodiscard]] std::size_t size() const;

private:
    TreeNode* root_;
    std::size_t count_;
};

class GraphNode final : public Node {
    friend class Graph;

private:
    explicit GraphNode(int label);

    std::list<int> neighbors_;
    GraphNode* next_vertex_;
};

class Graph {
public:
    Graph();
    ~Graph();
    Graph(const Graph&) = delete;
    Graph& operator=(const Graph&) = delete;
    Graph(Graph&&) = delete;
    Graph& operator=(Graph&&) = delete;

    [[nodiscard]] bool add_vertex(int label);
    [[nodiscard]] bool add_edge(int u, int v);
    [[nodiscard]] bool has_edge(int u, int v) const;
    // Copia nueva de la adyacencia: nullptr = vertice no registrado,
    // lista vacia = vertice aislado; el llamador es el dueno.
    [[nodiscard]] std::unique_ptr<std::list<int>> get_neighbors(int u) const;
    [[nodiscard]] bool is_empty() const;
    [[nodiscard]] std::size_t vertex_count() const;
    [[nodiscard]] std::size_t edge_count() const;

private:
    GraphNode* vertices_;
    std::size_t vertex_total_;
    std::size_t edges_;

    // Solo lectura: un objeto const no debe alcanzar nodos mutables.
    [[nodiscard]] GraphNode* find_vertex(int label);
    [[nodiscard]] const GraphNode* find_vertex(int label) const;
};

} // namespace data_structures_advanced

#endif // DATA_STRUCTURES_ADVANCED_H
