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
Because it uses an in-place quicksort method that uses a recursive algorithm, so (O(n) * stack frame size) will be used in the worst case and
(O(log n) * stack frame size) will be used on average.

Successfully report: https://contest.yandex.ru/contest/23815/run-report/89592846/
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

// Defining a Participant type that represents a contestant
using Participant = std::tuple<int, int, std::string>;
// Defining an iterator for a member list
using Iterator = std::vector<Participant>::iterator;
// Comparison function definition
using Comparator = const std::function<bool(const Participant&, const Participant&)>;

// Function to compare two participants
bool compare(const Participant& a, const Participant& b) {
    return a < b;
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
        std::string name;
        int score1, score2;
        std::cin >> name >> score1 >> score2;
        // Invert value and make tuple to use standard tuple comparison
        p = std::make_tuple(-score1, score2, name);
    }

    quick_sort_in_place(participants.begin(), participants.end(), compare);

    for (const auto &p: participants) {
        std::cout << std::get<2>(p) << std::endl;
    }
}