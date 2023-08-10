// https://contest.yandex.ru/contest/23638/problems/L/
#include <iostream>
#include <vector>

using Iterator = std::vector<int>::iterator;

Iterator bin_search(Iterator begin, Iterator end, int elem) {
    if (begin == end || *begin >= elem) {
        return begin;
    }

    auto middle = begin + (end - begin) / 2;
    if (*middle < elem) {
        return bin_search(middle + 1, end, elem);
    } else {
        return bin_search(begin, middle, elem);
    }
}

int main() {
    int n, s;
    std::cin >> n;
    std::vector<int> balances(n);

    for (int i = 0; i < n; i++) {
        std::cin >> balances[i];
    }
    std::cin >> s;

    auto first_day = bin_search(balances.begin(), balances.end(), s) - balances.begin();
    auto second_day = bin_search(balances.begin(), balances.end(), 2 * s) - balances.begin();

    std::cout << (first_day < n ? first_day + 1 : -1) << " " << (second_day < n ? second_day + 1 : -1) << std::endl;
}