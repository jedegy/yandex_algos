// https://contest.yandex.ru/contest/25596/problems/N/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

const int INF = 1000000;

void restore_days_used_coupons(std::vector<std::vector<int>>& dp, std::vector<int>& cost, std::deque<int>& used, int i, int j) {
    if (j < i) {
        if (j == 0) {
            if (i >= 1) {
                if (cost[i] > 500) {
                    used.push_back(i);
                    restore_days_used_coupons(dp, cost, used, i - 1, j + 1);
                } else {
                    if (dp[i][j] == dp[i - 1][j + 1]) {
                        used.push_back(i);
                        restore_days_used_coupons(dp, cost, used, i - 1, j + 1);
                    } else
                        restore_days_used_coupons(dp, cost, used, i - 1, j);
                }
            }
        } else {
            if (cost[i] <= 500) {
                if (dp[i - 1][j + 1] == dp[i][j]) {
                    used.push_back(i);
                    restore_days_used_coupons(dp, cost, used, i - 1, j + 1);
                } else {
                    restore_days_used_coupons(dp, cost, used, i - 1, j);
                }
            } else {
                if (dp[i - 1][j + 1] == dp[i][j]) {
                    used.push_back(i);
                    restore_days_used_coupons(dp, cost, used, i - 1, j + 1);
                } else {
                    restore_days_used_coupons(dp, cost, used, i - 1, j - 1);
                }
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 2, INF));
    std::vector<int> cost(n + 1);

    int coupons = 0;
    int total_cost = INF;

    for (int i = 1; i <= n; i++) {
        std::cin >> cost[i];
    }

    if (n == 1) {
        std::cout << cost[1] << " 0";
        return 0;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                if (i >= 1) {
                    if (cost[i] <= 500) {
                        dp[i][j] = std::min(dp[i - 1][j + 1], dp[i - 1][j] + cost[i]);
                    } else {
                        dp[i][j] = dp[i - 1][j + 1];
                    }
                } else {
                    dp[i][j] = 0;
                }
            } else {
                if (cost[i] > 500) {
                    dp[i][j] = std::min(dp[i - 1][j + 1], dp[i - 1][j - 1] + cost[i]);
                } else {
                    dp[i][j] = std::min(dp[i - 1][j + 1], dp[i - 1][j] + cost[i]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (total_cost >= dp[n][i]) {
            total_cost = dp[n][i];
            coupons = i;
        }
    }

    std::deque<int> used_coupons;
    restore_days_used_coupons(dp, cost, used_coupons, n, coupons);

    std::cout << total_cost << " " << used_coupons.size() << std::endl;

    while (!used_coupons.empty()) {
        std::cout << used_coupons.back() << " ";
        used_coupons.pop_back();
    }

    return 0;
}
