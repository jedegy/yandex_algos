// https://contest.yandex.ru/contest/24809/problems/M/
#include <vector>
#include <cassert>
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif


int siftUp(std::vector<int>& heap, int idx) {
    if (idx == 1)
        return idx;

    int parent_idx = idx / 2;
    if (heap[parent_idx] < heap[idx]) {
        std::swap(heap[parent_idx], heap[idx]);
        return siftUp(heap, parent_idx);
    }

    return idx;
}

#ifndef REMOTE_JUDGE
void test() {
    std::vector<int> sample = {-1, 12, 6, 8, 3, 15, 7};
    int a = siftUp(sample, 5);
    assert(a == 1);
}


int main() {
    test();
}
#endif