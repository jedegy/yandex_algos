// https://contest.yandex.ru/contest/24809/problems/I/
#include <iostream>
#include <vector>
using namespace std;

long long get_num_bin_search_trees(int n) {
    vector<long long> nums(n + 1, 0);
    nums[0] = nums[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            nums[i] += nums[j] * nums[i - j - 1];
        }
    }

    return nums[n];
}

int main() {
    int n;
    std::cin >> n;
    std::cout << get_num_bin_search_trees(n) << std::endl;

    return 0;
}
