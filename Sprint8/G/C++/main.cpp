// https://contest.yandex.ru/contest/26131/problems/G/
#include <iostream>
#include <vector>

bool check_equal(const std::vector<int>& s, int start, const std::vector<int>& pattern, int shift) {
    for (int i = 0; i < pattern.size(); ++i) {
        if (s[start + i] != pattern[i] + shift) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> measure_res(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> measure_res[i];
    }

    std::cin >> m;
    std::vector<int> sample(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> sample[i];
    }

    for (int i = 0; i <= n - m; ++i) {
        int shift = measure_res[i] - sample[0];
        if (check_equal(measure_res, i, sample, shift)) {
            std::cout << i + 1 << " ";
        }
    }

    return 0;
}
