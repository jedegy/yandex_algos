// https://contest.yandex.ru/contest/23638/problems/O/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    long long k;
    std::cin >> n;
    std::vector<int> areas(n);

    for (int i = 0; i < n; i++) {
        std::cin >> areas[i];
    }
    std::cin >> k;

    std::sort(areas.begin(), areas.end());

    long long left = 0, right = areas.back() - areas.front(), result = -1;

    while (left <= right) {
        long long mid = (left + right) / 2;

        long long count = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && areas[j] - areas[i] <= mid) {
                j++;
            }
            count += j - i - 1;
        }

        if (count < k) {
            left = mid + 1;
        } else {
            result = mid;
            right = mid - 1;
        }
    }

    std::cout << result << std::endl;
    return 0;
}
