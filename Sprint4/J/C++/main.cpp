// https://contest.yandex.ru/contest/23991/problems/J/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

int main() {
    int n;
    long long s;
    std::cin >> n;
    std::cin >> s;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    std::map<long long, std::vector<std::pair<long long, long long >>> hash_pairs;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            hash_pairs[arr[i] + arr[j]].emplace_back(i, j);
        }
    }

    std::set<std::vector<int>> result;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            long long sum = arr[i] + arr[j];
            if (hash_pairs.find(s - sum) != hash_pairs.end()) {
                for (auto &p: hash_pairs[s - sum]) {

                    if (p.first != i && p.first != j && p.second != i && p.second != j) {
                        std::vector<int> quad = {arr[i], arr[j], arr[p.first], arr[p.second]};
                        sort(quad.begin(), quad.end());
                        result.insert(quad);
                    }
                }
            }
        }
    }

    std::cout << result.size() << std::endl;
    for (auto &quad: result) {
        for (int num: quad)
            std::cout << num << " ";
        std::cout << std::endl;
    }

    return 0;
}