#include <gtest/gtest.h>

#include <functional>
#include <initializer_list>
#include <list>
#include <memory>

#include "../include/data_structures_advanced.h"

namespace {

using data_structures_advanced::BinaryTree;
using data_structures_advanced::Graph;
using data_structures_advanced::TreeNode;

constexpr int kRootValue = 10;
constexpr int kLeftValue = 20;
constexpr int kRightValue = 30;
constexpr int kTreeRoot = 50;
constexpr int kTreeLow = 30;
constexpr int kTreeHigh = 70;
constexpr int kTreeLowLeft = 20;
constexpr int kTreeLowRight = 40;
constexpr int kMissingValue = 99;
constexpr int kLabelA = 10;
constexpr int kLabelB = 30;
constexpr int kLabelC = 50;
constexpr int kLabelD = 70;
constexpr int kMissingLabelA = 98;
constexpr int kMissingLabelB = 99;

using Neighbors = std::list<int>;

struct NamedCase {
    const char* name;
    std::function<void()> verify;
};

void run_cases(std::initializer_list<NamedCase> cases)
{
    for (const NamedCase& test_case : cases) {
        SCOPED_TRACE(test_case.name);
        test_case.verify();
    }
}

void expect_neighbors(const Graph& graph, int label, const Neighbors& expected, const char* subject)
{
    const std::unique_ptr<Neighbors> actual = graph.get_neighbors(label);
    ASSERT_NE(actual, nullptr) << subject << " should return a neighbour sequence for a registered vertex";
    EXPECT_EQ(*actual, expected) << subject << " should return the expected sorted neighbours";
}

void expect_counts(const Graph& graph, std::size_t vertices, std::size_t edges, const char* subject)
{
    EXPECT_EQ(graph.vertex_count(), vertices) << subject << " should report the expected vertex count";
    EXPECT_EQ(graph.edge_count(), edges) << subject << " should report the expected edge count";
}

void expect_tree_contains(const BinaryTree& tree, std::initializer_list<int> values, const char* subject)
{
    for (int value : values) {
        EXPECT_TRUE(tree.contains(value)) << subject << " should contain " << value;
    }
}

class DataStructuresAdvancedTests : public ::testing::Test {};

TEST_F(DataStructuresAdvancedTests, treeNodeOperations)
{
    run_cases({
        {"create a tree node", [] {
             TreeNode node(kRootValue);
             EXPECT_EQ(node.get_value(), kRootValue) << "TreeNode should retain its initialized value";
         }},
        {"absent initial links", [] {
             TreeNode node(kRootValue);
             EXPECT_EQ(node.get_left(), nullptr) << "TreeNode should start with an absent left link";
             EXPECT_EQ(node.get_right(), nullptr) << "TreeNode should start with an absent right link";
         }},
        {"link two children", [] {
             TreeNode parent(kRootValue);
             TreeNode left(kLeftValue);
             TreeNode right(kRightValue);
             parent.set_left(&left);
             parent.set_right(&right);

             ASSERT_NE(parent.get_left(), nullptr) << "TreeNode should expose the linked left child";
             ASSERT_NE(parent.get_right(), nullptr) << "TreeNode should expose the linked right child";
             EXPECT_EQ(parent.get_left()->get_value(), kLeftValue) << "Left child should hold its value";
             EXPECT_EQ(parent.get_right()->get_value(), kRightValue) << "Right child should hold its value";
         }},
        {"traverse each link", [] {
             TreeNode parent(kRootValue);
             TreeNode left(kLeftValue);
             TreeNode right(kRightValue);
             parent.set_left(&left);
             parent.set_right(&right);

             const TreeNode* reached_left = parent.get_left();
             const TreeNode* reached_right = parent.get_right();
             ASSERT_NE(reached_left, nullptr) << "Traversal should reach the left child";
             ASSERT_NE(reached_right, nullptr) << "Traversal should reach the right child";
             EXPECT_EQ(reached_left->get_value(), kLeftValue) << "Left traversal should lead to its value";
             EXPECT_EQ(reached_right->get_value(), kRightValue) << "Right traversal should lead to its value";
             EXPECT_EQ(reached_left->get_left(), nullptr) << "Left child should have an absent left link";
             EXPECT_EQ(reached_left->get_right(), nullptr) << "Left child should have an absent right link";
             EXPECT_EQ(reached_right->get_left(), nullptr) << "Right child should have an absent left link";
             EXPECT_EQ(reached_right->get_right(), nullptr) << "Right child should have an absent right link";
         }},
        {"unlink children", [] {
             TreeNode parent(kRootValue);
             TreeNode left(kLeftValue);
             TreeNode right(kRightValue);
             parent.set_left(&left);
             parent.set_right(&right);

             parent.set_left(nullptr);
             EXPECT_EQ(parent.get_left(), nullptr) << "TreeNode should have no left child after unlinking it";
             EXPECT_EQ(parent.get_value(), kRootValue) << "TreeNode should keep its value after unlinking left";
             ASSERT_NE(parent.get_right(), nullptr) << "TreeNode should keep its right child after unlinking left";
             EXPECT_EQ(parent.get_right()->get_value(), kRightValue)
                 << "TreeNode should keep the right child value after unlinking left";

             parent.set_right(nullptr);
             EXPECT_EQ(parent.get_left(), nullptr) << "TreeNode should have an absent left link after both unlinks";
             EXPECT_EQ(parent.get_right(), nullptr) << "TreeNode should have an absent right link after both unlinks";
             EXPECT_EQ(parent.get_value(), kRootValue) << "TreeNode should keep its value after both unlinks";
         }},
    });
}

TEST_F(DataStructuresAdvancedTests, binaryTreeOperations)
{
    run_cases({
        {"create empty", [] {
             BinaryTree tree;
             EXPECT_TRUE(tree.is_empty()) << "BinaryTree should be empty after initialization";
             EXPECT_EQ(tree.size(), 0U) << "BinaryTree should have size zero after initialization";
             EXPECT_FALSE(tree.contains(kTreeRoot)) << "Empty BinaryTree should not contain any value";
         }},
        {"insert the root", [] {
             BinaryTree tree;
             EXPECT_TRUE(tree.insert(kTreeRoot)) << "BinaryTree should accept the root insertion";
             EXPECT_EQ(tree.size(), 1U) << "BinaryTree should count the root";
             EXPECT_FALSE(tree.is_empty()) << "BinaryTree should not be empty after inserting the root";
             EXPECT_TRUE(tree.contains(kTreeRoot)) << "BinaryTree should contain the inserted root";
         }},
        {"insert lower and higher", [] {
             BinaryTree tree;
             EXPECT_TRUE(tree.insert(kTreeRoot)) << "BinaryTree should accept the root";
             EXPECT_TRUE(tree.insert(kTreeLow)) << "BinaryTree should accept a lower value";
             EXPECT_TRUE(tree.insert(kTreeHigh)) << "BinaryTree should accept a higher value";
             EXPECT_EQ(tree.size(), 3U) << "BinaryTree should count three distinct values";
             expect_tree_contains(tree, {kTreeRoot, kTreeLow, kTreeHigh}, "BinaryTree");
         }},
        {"multilevel branches", [] {
             BinaryTree tree;
             for (int value : {kTreeRoot, kTreeLow, kTreeHigh, kTreeLowLeft, kTreeLowRight}) {
                 EXPECT_TRUE(tree.insert(value)) << "BinaryTree should accept " << value;
             }
             EXPECT_EQ(tree.size(), 5U) << "BinaryTree should count five distinct values";
             expect_tree_contains(tree, {kTreeRoot, kTreeLow, kTreeHigh, kTreeLowLeft, kTreeLowRight}, "BinaryTree");
         }},
        {"missing value in nonempty tree", [] {
             BinaryTree tree;
             EXPECT_TRUE(tree.insert(kTreeRoot)) << "BinaryTree should accept the root";
             EXPECT_FALSE(tree.contains(kMissingValue)) << "BinaryTree should not contain a value never inserted";
             EXPECT_EQ(tree.size(), 1U) << "BinaryTree lookup should not change the size";
             EXPECT_TRUE(tree.contains(kTreeRoot)) << "BinaryTree should still contain the root after a miss";
         }},
        {"idempotent duplicate", [] {
             BinaryTree tree;
             for (int value : {kTreeRoot, kTreeLow, kTreeHigh, kTreeLow}) {
                 EXPECT_TRUE(tree.insert(value)) << "BinaryTree should succeed inserting " << value;
             }
             EXPECT_EQ(tree.size(), 3U) << "BinaryTree should not grow when inserting a duplicate";
             expect_tree_contains(tree, {kTreeRoot, kTreeLow, kTreeHigh}, "BinaryTree");
         }},
        {"ordered insertions", [] {
             BinaryTree tree;
             for (int value : {kTreeLowLeft, kTreeLow, kTreeLowRight, kTreeRoot, kTreeHigh}) {
                 EXPECT_TRUE(tree.insert(value)) << "BinaryTree should accept " << value;
             }
             EXPECT_EQ(tree.size(), 5U) << "BinaryTree should count five ascending values";
             expect_tree_contains(tree, {kTreeLowLeft, kTreeLow, kTreeLowRight, kTreeRoot, kTreeHigh}, "BinaryTree");
             EXPECT_FALSE(tree.contains(kMissingValue)) << "BinaryTree should not contain a missing value";
         }},
    });
}

TEST_F(DataStructuresAdvancedTests, graphOperations)
{
    run_cases({
        {"create empty", [] {
             Graph graph;
             EXPECT_TRUE(graph.is_empty()) << "Graph should be empty after initialization";
             expect_counts(graph, 0U, 0U, "Empty Graph");
             EXPECT_FALSE(graph.has_edge(kLabelA, kLabelB)) << "Empty Graph should have no edges";
             EXPECT_EQ(graph.get_neighbors(kLabelA), nullptr) << "Empty Graph should fail neighbours of a missing vertex";
         }},
        {"isolated vertex", [] {
             Graph graph;
             EXPECT_TRUE(graph.add_vertex(kLabelA)) << "Graph should register a vertex";
             EXPECT_FALSE(graph.is_empty()) << "Graph should not be empty after adding a vertex";
             expect_counts(graph, 1U, 0U, "Graph with an isolated vertex");
             expect_neighbors(graph, kLabelA, {}, "Isolated vertex");
         }},
        {"nonconsecutive labels and directed edge", [] {
             Graph graph;
             EXPECT_TRUE(graph.add_vertex(kLabelA)) << "Graph should register the first label";
             EXPECT_TRUE(graph.add_vertex(kLabelD)) << "Graph should register the second label";
             EXPECT_TRUE(graph.add_edge(kLabelA, kLabelD)) << "Graph should add an edge between registered vertices";
             EXPECT_TRUE(graph.has_edge(kLabelA, kLabelD)) << "Graph should report the forward edge";
             EXPECT_FALSE(graph.has_edge(kLabelD, kLabelA)) << "Graph should not report the reverse edge";
             expect_counts(graph, 2U, 1U, "Directed Graph");
         }},
        {"duplicate vertex preserves adjacency", [] {
             Graph graph;
             EXPECT_TRUE(graph.add_vertex(kLabelA)) << "Graph should register the first label";
             EXPECT_TRUE(graph.add_vertex(kLabelB)) << "Graph should register the second label";
             EXPECT_TRUE(graph.add_edge(kLabelA, kLabelB)) << "Graph should add the edge";
             EXPECT_TRUE(graph.add_vertex(kLabelA)) << "Graph should succeed on a duplicate vertex";
             expect_counts(graph, 2U, 1U, "Graph after duplicate vertex");
             expect_neighbors(graph, kLabelA, {kLabelB}, "Duplicate vertex");
         }},
        {"duplicate edge", [] {
             Graph graph;
             EXPECT_TRUE(graph.add_vertex(kLabelA)) << "Graph should register the first label";
             EXPECT_TRUE(graph.add_vertex(kLabelB)) << "Graph should register the second label";
             EXPECT_TRUE(graph.add_edge(kLabelA, kLabelB)) << "Graph should add the edge";
             EXPECT_TRUE(graph.add_edge(kLabelA, kLabelB)) << "Graph should succeed on a duplicate edge";
             expect_counts(graph, 2U, 1U, "Graph after duplicate edge");
             expect_neighbors(graph, kLabelA, {kLabelB}, "Duplicate edge");
         }},
        {"missing endpoint without mutation", [] {
             Graph graph;
             EXPECT_TRUE(graph.add_vertex(kLabelA)) << "Graph should register the first label";
             EXPECT_TRUE(graph.add_vertex(kLabelB)) << "Graph should register the second label";
             EXPECT_TRUE(graph.add_edge(kLabelA, kLabelB)) << "Graph should add the edge";
             EXPECT_FALSE(graph.add_edge(kLabelA, kMissingLabelB)) << "Graph should fail with a missing target";
             EXPECT_FALSE(graph.add_edge(kMissingLabelB, kLabelA)) << "Graph should fail with a missing source";
             EXPECT_FALSE(graph.add_edge(kMissingLabelA, kMissingLabelB)) << "Graph should fail with both endpoints missing";
             EXPECT_FALSE(graph.add_edge(kMissingLabelB, kMissingLabelB)) << "Graph should fail a self-loop on a missing vertex";
             expect_counts(graph, 2U, 1U, "Graph after failed edges");
             expect_neighbors(graph, kLabelA, {kLabelB}, "Vertex A after failed edges");
             expect_neighbors(graph, kLabelB, {}, "Vertex B after failed edges");
             EXPECT_FALSE(graph.has_edge(kLabelA, kMissingLabelB)) << "Graph should not report a failed target edge";
             EXPECT_FALSE(graph.has_edge(kMissingLabelB, kLabelA)) << "Graph should not report a failed source edge";
             EXPECT_FALSE(graph.has_edge(kMissingLabelA, kMissingLabelB)) << "Graph should not report a failed missing edge";
             EXPECT_FALSE(graph.has_edge(kMissingLabelB, kMissingLabelB)) << "Graph should not report a failed missing loop";
             EXPECT_EQ(graph.get_neighbors(kMissingLabelA), nullptr) << "Graph should not create the first missing vertex";
             EXPECT_EQ(graph.get_neighbors(kMissingLabelB), nullptr) << "Graph should not create the second missing vertex";
         }},
        {"sorted neighbours and counts", [] {
             Graph graph;
             for (int label : {kLabelA, kLabelB, kLabelC, kLabelD}) {
                 EXPECT_TRUE(graph.add_vertex(label)) << "Graph should register " << label;
             }
             EXPECT_TRUE(graph.add_edge(kLabelA, kLabelD)) << "Graph should add 10 -> 70";
             EXPECT_TRUE(graph.add_edge(kLabelA, kLabelB)) << "Graph should add 10 -> 30";
             EXPECT_TRUE(graph.add_edge(kLabelA, kLabelC)) << "Graph should add 10 -> 50";
             EXPECT_TRUE(graph.add_edge(kLabelB, kLabelC)) << "Graph should add 30 -> 50";
             expect_neighbors(graph, kLabelA, {kLabelB, kLabelC, kLabelD}, "Vertex 10");
             expect_neighbors(graph, kLabelB, {kLabelC}, "Vertex 30");
             expect_neighbors(graph, kLabelC, {}, "Vertex 50");
             expect_neighbors(graph, kLabelD, {}, "Vertex 70");
             expect_counts(graph, 4U, 4U, "Graph with sorted neighbours");
         }},
        {"missing-edge query", [] {
             Graph graph;
             EXPECT_TRUE(graph.add_vertex(kLabelA)) << "Graph should register the first label";
             EXPECT_TRUE(graph.add_vertex(kLabelB)) << "Graph should register the second label";
             EXPECT_FALSE(graph.has_edge(kLabelA, kLabelB)) << "Graph should not report an absent edge";
             expect_counts(graph, 2U, 0U, "Graph without edges");
             EXPECT_FALSE(graph.is_empty()) << "Graph with vertices should not be empty";
         }},
        {"neighbours of missing vertex", [] {
             Graph graph;
             EXPECT_TRUE(graph.add_vertex(kLabelA)) << "Graph should register a vertex";
             EXPECT_EQ(graph.get_neighbors(kMissingLabelB), nullptr)
                 << "Graph should fail neighbours of a missing vertex";
             expect_neighbors(graph, kLabelA, {}, "Registered isolated vertex");
             expect_counts(graph, 1U, 0U, "Graph after missing-vertex query");
         }},
        {"self-loop and duplicate", [] {
             Graph graph;
             EXPECT_TRUE(graph.add_vertex(kLabelA)) << "Graph should register a vertex";
             EXPECT_TRUE(graph.add_edge(kLabelA, kLabelA)) << "Graph should add a self-loop";
             EXPECT_TRUE(graph.add_edge(kLabelA, kLabelA)) << "Graph should succeed on a duplicate self-loop";
             EXPECT_TRUE(graph.has_edge(kLabelA, kLabelA)) << "Graph should report the self-loop";
             expect_neighbors(graph, kLabelA, {kLabelA}, "Self-loop vertex");
             expect_counts(graph, 1U, 1U, "Graph with a self-loop");
         }},
        {"neighbour-result isolation", [] {
             Graph graph;
             for (int label : {kLabelA, kLabelB, kLabelC}) {
                 EXPECT_TRUE(graph.add_vertex(label)) << "Graph should register " << label;
             }
             EXPECT_TRUE(graph.add_edge(kLabelA, kLabelB)) << "Graph should add 10 -> 30";

             const std::unique_ptr<Neighbors> saved = graph.get_neighbors(kLabelA);
             ASSERT_NE(saved, nullptr) << "Graph should return neighbours of a registered vertex";
             std::unique_ptr<Neighbors> other_copy = graph.get_neighbors(kLabelA);
             ASSERT_NE(other_copy, nullptr) << "Graph should return another neighbour copy";
             other_copy->push_back(kMissingLabelB);

             expect_neighbors(graph, kLabelA, {kLabelB, kLabelC}, "Fresh neighbour query");
             expect_counts(graph, 3U, 2U, "Graph after isolation scenario");
         }},
    });
}

} // namespace
