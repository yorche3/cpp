#include <gtest/gtest.h>

#include <functional>
#include <initializer_list>

#include "../include/data_structures_basics.h"

namespace {

using data_structures_basics::LinkedList;
using data_structures_basics::Node;
using data_structures_basics::Queue;
using data_structures_basics::Stack;

constexpr int kFirstValue = 10;
constexpr int kSecondValue = 20;
constexpr int kHeadValue = 5;
constexpr int kTopValue = 30;
constexpr int kReusedValue = 40;
constexpr int kMissingValue = 99;
constexpr int kFailureValue = -1;

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

class DataStructuresBasicsTests : public ::testing::Test {};

TEST_F(DataStructuresBasicsTests, nodeOperations)
{
    Node first_node(kFirstValue);

    run_cases({
        {"initialize and observe value/link", [&] {
             EXPECT_EQ(first_node.get_value(), kFirstValue)
                 << "Node should retain its initialized value";
             EXPECT_EQ(first_node.get_next(), nullptr)
                 << "Node should have no next node after initialization";
         }},
        {"initialize another node, link and traverse", [&] {
             Node second_node(kSecondValue);
             first_node.set_next(&second_node);

             ASSERT_NE(first_node.get_next(), nullptr)
                 << "Node should link to the supplied next node";
             EXPECT_EQ(first_node.get_next()->get_value(), kSecondValue)
                 << "Node should expose the linked node value";
             EXPECT_EQ(second_node.get_next(), nullptr)
                 << "Newly initialized linked node should have no next node";
         }},
    });
}

TEST_F(DataStructuresBasicsTests, linkedListOperations)
{
    LinkedList list;

    run_cases({
        {"empty state", [&] {
             EXPECT_TRUE(list.is_empty()) << "LinkedList should be empty after initialization";
             EXPECT_EQ(list.size(), 0U) << "LinkedList should have size zero after initialization";
             EXPECT_EQ(list.get_head(), kFailureValue)
                 << "LinkedList should return the failure indicator when empty";
         }},
        {"insert at both ends", [&] {
             list.insert_tail(kFirstValue);
             list.insert_tail(kSecondValue);
             list.insert_head(kHeadValue);
             list.insert_tail(kFirstValue);

             EXPECT_EQ(list.size(), 4U) << "LinkedList should count all inserted values";
             EXPECT_EQ(list.get_head(), kHeadValue)
                 << "LinkedList should expose the value inserted at its head";
         }},
        {"delete first occurrence", [&] {
             EXPECT_EQ(list.delete_value(kFirstValue), 1)
                 << "LinkedList should report success when deleting a present value";
             EXPECT_EQ(list.get_head(), kHeadValue)
                 << "LinkedList should preserve its head after deleting the first middle value";
             EXPECT_EQ(list.size(), 3U)
                 << "LinkedList should reduce its size after a successful deletion";
         }},
        {"absent value", [&] {
             EXPECT_EQ(list.delete_value(kMissingValue), kFailureValue)
                 << "LinkedList should return the failure indicator for an absent value";
             EXPECT_EQ(list.get_head(), kHeadValue)
                 << "LinkedList should preserve its contents when deleting an absent value";
             EXPECT_EQ(list.size(), 3U)
                 << "LinkedList should preserve its size when deleting an absent value";
         }},
        {"empty the list", [&] {
             EXPECT_EQ(list.delete_value(kHeadValue), 1)
                 << "LinkedList should delete its head value";
             EXPECT_EQ(list.delete_value(kSecondValue), 1)
                 << "LinkedList should delete its remaining middle value";
             EXPECT_EQ(list.delete_value(kFirstValue), 1)
                 << "LinkedList should delete its remaining tail value";
             EXPECT_TRUE(list.is_empty()) << "LinkedList should be empty after all values are deleted";
             EXPECT_EQ(list.size(), 0U) << "LinkedList should have size zero after all values are deleted";
             EXPECT_EQ(list.get_head(), kFailureValue)
                 << "LinkedList should return the failure indicator after becoming empty";
         }},
    });
}

TEST_F(DataStructuresBasicsTests, stackOperations)
{
    Stack stack;

    run_cases({
        {"empty state and failed removal", [&] {
             EXPECT_TRUE(stack.is_empty()) << "Stack should be empty after initialization";
             EXPECT_EQ(stack.size(), 0U) << "Stack should have size zero after initialization";
             EXPECT_EQ(stack.peek(), kFailureValue)
                 << "Stack should return the failure indicator when peeking while empty";
             EXPECT_EQ(stack.pop(), kFailureValue)
                 << "Stack should return the failure indicator when popping while empty";
         }},
        {"LIFO and non-mutating peek", [&] {
             stack.push(kFirstValue);
             stack.push(kSecondValue);
             stack.push(kTopValue);

             EXPECT_EQ(stack.peek(), kTopValue) << "Stack should peek at the most recently pushed value";
             EXPECT_EQ(stack.size(), 3U) << "Stack peek should not change its size";
         }},
        {"removal and reuse", [&] {
             EXPECT_EQ(stack.pop(), kTopValue) << "Stack should pop its current top value";
             stack.push(kReusedValue);
             EXPECT_EQ(stack.pop(), kReusedValue) << "Stack should pop a value pushed after removal";
             EXPECT_EQ(stack.pop(), kSecondValue) << "Stack should preserve LIFO order after reuse";
             EXPECT_EQ(stack.pop(), kFirstValue) << "Stack should pop its oldest remaining value last";
             EXPECT_TRUE(stack.is_empty()) << "Stack should be empty after all values are popped";
             EXPECT_EQ(stack.size(), 0U) << "Stack should have size zero after all values are popped";
         }},
        {"empty after removal", [&] {
             EXPECT_EQ(stack.pop(), kFailureValue)
                 << "Stack should return the failure indicator after becoming empty";
             EXPECT_TRUE(stack.is_empty()) << "Stack should remain empty after a failed pop";
         }},
    });
}

TEST_F(DataStructuresBasicsTests, queueOperations)
{
    Queue queue;

    run_cases({
        {"empty state and failed removal", [&] {
             EXPECT_TRUE(queue.is_empty()) << "Queue should be empty after initialization";
             EXPECT_EQ(queue.size(), 0U) << "Queue should have size zero after initialization";
             EXPECT_EQ(queue.peek(), kFailureValue)
                 << "Queue should return the failure indicator when peeking while empty";
             EXPECT_EQ(queue.dequeue(), kFailureValue)
                 << "Queue should return the failure indicator when dequeuing while empty";
         }},
        {"FIFO and non-mutating peek", [&] {
             queue.enqueue(kFirstValue);
             queue.enqueue(kSecondValue);
             queue.enqueue(kTopValue);

             EXPECT_EQ(queue.peek(), kFirstValue) << "Queue should peek at the first enqueued value";
             EXPECT_EQ(queue.size(), 3U) << "Queue peek should not change its size";
         }},
        {"removal and reuse", [&] {
             EXPECT_EQ(queue.dequeue(), kFirstValue) << "Queue should dequeue its front value";
             queue.enqueue(kReusedValue);
             EXPECT_EQ(queue.dequeue(), kSecondValue) << "Queue should preserve FIFO order after reuse";
             EXPECT_EQ(queue.dequeue(), kTopValue) << "Queue should dequeue the next original value";
             EXPECT_EQ(queue.dequeue(), kReusedValue) << "Queue should dequeue the reused tail value last";
             EXPECT_TRUE(queue.is_empty()) << "Queue should be empty after all values are dequeued";
             EXPECT_EQ(queue.size(), 0U) << "Queue should have size zero after all values are dequeued";
         }},
        {"empty after removal", [&] {
             EXPECT_EQ(queue.dequeue(), kFailureValue)
                 << "Queue should return the failure indicator after becoming empty";
             EXPECT_TRUE(queue.is_empty()) << "Queue should remain empty after a failed dequeue";
         }},
    });
}

} // namespace
