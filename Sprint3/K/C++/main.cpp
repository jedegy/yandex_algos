// https://contest.yandex.ru/contest/23638/problems/K/
#include <vector>

using Iterator = std::vector<int>::iterator;
using CIterator = std::vector<int>::const_iterator;

std::vector<int> merge(
        CIterator left_begin, CIterator left_end,
        CIterator right_begin, CIterator right_end) {
    std::vector<int> result;
    auto left = left_begin;
    auto right = right_begin;


    while ((left < left_end) && (right < right_end)) {
        if (*left <= *right) {
            result.push_back(*left);
            left++;
        } else {
            result.push_back(*right);
            right++;
        }
    }

    while (left < left_end) {
        result.push_back(*left);
        left++;
    }

    while (right < right_end) {
        result.push_back(*right);
        right++;
    }

    return result;
}

void merge_sort(Iterator begin, Iterator end) {
    if ((end - begin) <= 1) {
        return;
    }

    Iterator middle = begin + (end - begin) / 2;

    merge_sort(begin, middle);
    merge_sort(middle, end);

    auto sorted = merge(begin, middle, middle, end);
    std::move(sorted.begin(), sorted.end(), begin);
}