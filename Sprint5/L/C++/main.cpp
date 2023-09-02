// https://contest.yandex.ru/contest/24809/problems/L/
#include <vector>
#include <cassert>
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif


int siftDown(std::vector<int>& heap, int idx) {
    int left = 2 * idx;
    int right = 2 * idx + 1;

    if (left >= heap.size()) {
        return idx;
    }

    int idx_max = left;
    if (right < heap.size() && heap[left] < heap[right]) {
        idx_max = right;
    }

    if (heap[idx] < heap[idx_max]) {
        std::swap(heap[idx], heap[idx_max]);
        return siftDown(heap, idx_max);
    }

    return idx;
}

#ifndef REMOTE_JUDGE
void test() {
    std::vector<int> sample = {-1, 12, 1, 8, 3, 4, 7};
    assert(siftDown(sample, 2) == 5);
}


int main() {
    test();
}
#endif