// https://contest.yandex.ru/contest/25596/problems/J/
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::vector<int> dp(n, 1);
    std::vector<int> prev(n, -1);

    int max_len = 1, last_index = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > max_len) {
            max_len = dp[i];
            last_index = i;
        }
    }

    std::cout << max_len << std::endl;

    std::vector<int> result;
    while (last_index != -1) {
        result.push_back(last_index + 1);
        last_index = prev[last_index];
    }

    for (int i = result.size() - 1; i >= 0; --i) {
        std::cout << result[i] << " ";
    }

    return 0;
}
