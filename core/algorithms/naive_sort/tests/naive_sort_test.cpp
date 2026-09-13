#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../include/naive_sort.h"

namespace
{

using SortFn = std::vector<int> (*)(std::vector<int>);

/*
 * Fixtures: one named constant per input/output case.
 * Each sort function takes its argument by value, so every call works on its
 * own copy and the shared fixtures are never mutated.
 */
const std::vector<int> STANDARD_INPUT{5, 2, 9, 1, 5, 6};
const std::vector<int> STANDARD_OUTPUT{1, 2, 5, 5, 6, 9};

const std::vector<int> SORTED_INPUT{1, 2, 3, 4, 5};
const std::vector<int> SORTED_OUTPUT{1, 2, 3, 4, 5};

const std::vector<int> REVERSE_INPUT{5, 4, 3, 2, 1};
const std::vector<int> REVERSE_OUTPUT{1, 2, 3, 4, 5};

const std::vector<int> IDENTICAL_INPUT{7, 7, 7, 7};
const std::vector<int> IDENTICAL_OUTPUT{7, 7, 7, 7};

const std::vector<int> NEGATIVE_INPUT{3, -1, 4, -5, 0};
const std::vector<int> NEGATIVE_OUTPUT{-5, -1, 0, 3, 4};

const std::vector<int> SINGLE_INPUT{42};
const std::vector<int> SINGLE_OUTPUT{42};

const std::vector<int> EMPTY_INPUT{};
const std::vector<int> EMPTY_OUTPUT{};

/* Runs the 7 shared cases against any sort function. */
void assertSortsAllCases(SortFn sort, const std::string &algorithm)
{
    EXPECT_EQ(sort(STANDARD_INPUT), STANDARD_OUTPUT)
        << algorithm << " should sort an unsorted array";
    EXPECT_EQ(sort(SORTED_INPUT), SORTED_OUTPUT)
        << algorithm << " should sort an already sorted array";
    EXPECT_EQ(sort(REVERSE_INPUT), REVERSE_OUTPUT)
        << algorithm << " should sort a reverse order array";
    EXPECT_EQ(sort(IDENTICAL_INPUT), IDENTICAL_OUTPUT)
        << algorithm << " should sort identical elements";
    EXPECT_EQ(sort(NEGATIVE_INPUT), NEGATIVE_OUTPUT)
        << algorithm << " should sort with negative numbers";
    EXPECT_EQ(sort(SINGLE_INPUT), SINGLE_OUTPUT)
        << algorithm << " should sort a single element";
    EXPECT_EQ(sort(EMPTY_INPUT), EMPTY_OUTPUT)
        << algorithm << " should sort an empty array";
}

} // namespace

TEST(NaiveSortTest, selection_sort)
{
    assertSortsAllCases(selection_sort, "selection_sort");
}

TEST(NaiveSortTest, bubble_sort)
{
    assertSortsAllCases(bubble_sort, "bubble_sort");
}

TEST(NaiveSortTest, insertion_sort)
{
    assertSortsAllCases(insertion_sort, "insertion_sort");
}
