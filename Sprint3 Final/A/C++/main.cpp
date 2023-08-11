/*
-- WORKING PRINCIPLE --
The solution is based on a modification of the binary search algorithm to work with "broken" sorted arrays.
First, the "pivot" point in the array is determined, then a normal binary search is used, taking into account this point.

-- PROOF OF CORRECTNESS --
The `search_pivot` function correctly finds the pivot point index in a broken array using the properties of the sorted array.
The `search_in_broken_array` function correctly performs a binary search, given offset due to rotation.

The methods correctly handle edge cases, such as finding elements that are before and after the rotation.

-- TIME COMPLEXITY --
The time complexity of pivot and binary search in a broken array is O(log n), where n is the size of the array.

-- SPACE COMPLEXITY --
Since only a few additional variables are used to store indexes and there are no additional data structures, the space complexity is O(1).

Successfully report: https://contest.yandex.ru/contest/23815/run-report/89576799/
*/
//#include "solution.h"
#include <vector>
#include <cassert>

// A function to find the pivot of rotation in a broken array.
// The pivot of rotation is the index of the largest element.
int search_pivot(const std::vector<int>& vec) {
    int left = 0;
    int right = vec.size() - 1;

    while (left < right) {
        int middle = left + (right - left) / 2;
        if (vec[middle] > vec[right]) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

// A function to perform a binary search on a broken array.
// If the element is found, returns its index; otherwise returns -1.
int broken_search(const std::vector<int>& vec, int k) {
    int left = 0;
    int right = vec.size() - 1;
    int pivot = search_pivot(vec);

    // Directly compare with the pivot value first
    if (vec[pivot] == k)
        return pivot;

    // If the first element of the array is less than the target, then look in the first half (before the pivot).
    // Otherwise, look in the second half (after the pivot).
    if (vec[0] <= k)
        // Array already sorted?
        if (!pivot)
            right = vec.size() - 1;
        else
            right = pivot - 1;
    else
        left = pivot;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (vec[middle] == k) {
            return middle;
        } else if (vec[middle] < k) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

void test() {
    std::vector<int> arr = {12, 41, 122, 411, 412, 1222, 3000, 12222, 122222};
    assert(6 == broken_search(arr, 3000));
}