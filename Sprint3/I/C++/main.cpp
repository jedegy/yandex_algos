// https://contest.yandex.ru/contest/23638/problems/I/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

bool comparator(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main() {
    int n, k, id;
    std::cin >> n;

    std::map<int, int> student_ids;

    for (int i = 0; i < n; ++i) {
        std::cin >> id;
        student_ids[id]++;
    }

    std::cin >> k;

    std::vector<std::pair<int, int>> buckets(student_ids.begin(), student_ids.end());

    std::sort(buckets.begin(), buckets.end(), comparator);

    for (int i = 0; i < std::min(k, (int) buckets.size()); ++i) {
        std::cout << buckets[i].first << " ";
    }

    return 0;
}