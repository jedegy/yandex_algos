/*
-- WORKING PRINCIPLE --
This program implements a quick sort algorithm for sorting the results of sports programming competitions.
Each participant has a unique login, the number of solved problems and the amount of the fine.
Participants are sorted first by the number of solved problems, then by the size of the fine, and finally by login in lexicographic order.

-- PROOF OF CORRECTNESS --
The implemented algorithm correctly sorts the participants according to the specified criteria.
To compare two participants, the `compare` function is used, which takes into account all three criteria.
The quicksort algorithm is implemented using the `partition` and `quick_sort_in_place` functions.
It provides efficient and correct ordering of elements without consuming O(n) additional memory.

-- TIME COMPLEXITY --
The average time complexity of quicksort is O(n log n), but in the worst case it can be as high as O(n^2), depending on the choice of pivot.

-- SPACE COMPLEXITY --
Since the in-place quicksort method is used, no additional memory is required and the space complexity is O(1).

Successfully report: https://contest.yandex.ru/contest/23815/run-report/89577416/
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

// Defining a Participant type that represents a contestant
using Participant = std::tuple<std::string, int, int>;
// Defining an iterator for a member list
using Iterator = std::vector<Participant>::iterator;
// Comparison function definition
using Comparator = const std::function<bool(const Participant&, const Participant&)>;

// Function to compare two participants
bool compare(const Participant& a, const Participant& b) {
    if (std::get<1>(a) != std::get<1>(b)) return std::get<1>(a) > std::get<1>(b);
    if (std::get<2>(a) != std::get<2>(b)) return std::get<2>(a) < std::get<2>(b);
    return std::get<0>(a) < std::get<0>(b);
}

// Implementation of partition function for quick sort
Iterator partition(Iterator low, Iterator high, Comparator& comp) {
    // Selecting a pivot element
    Participant pivot = *(high - 1);
    auto left = low;
    auto right = high - 1;

    // Perform the separation process
    while (true) {
        while (left < right && comp(*left, pivot)) ++left;
        while (left < right && !comp(*right, pivot)) --right;

        if (left >= right) break;

        std::swap(*left, *right);
    }

    std::swap(*left, *(high - 1));
    return left;
}

// Implementing in-place quicksort
void quick_sort_in_place(Iterator low, Iterator high, Comparator& comp) {
    if (low < high) {
        auto pivot = partition(low, high, comp);

        // Recursively sort the left side
        quick_sort_in_place(low, pivot, comp);
        // Recursively sort the right side
        quick_sort_in_place(pivot + 1, high, comp);
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Participant> participants(n);

    for (auto &p: participants) {
        std::cin >> std::get<0>(p) >> std::get<1>(p) >> std::get<2>(p);
    }

    quick_sort_in_place(participants.begin(), participants.end(), compare);

    for (const auto &p: participants) {
        std::cout << std::get<0>(p) << std::endl;
    }
}