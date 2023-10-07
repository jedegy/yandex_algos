// https://contest.yandex.ru/contest/25596/problems/C/
#include <iostream>
#include <vector>
#include <algorithm>

struct Bunch {
    long long kilo, price;
};

bool compare(const Bunch &a, const Bunch &b) {
    if (a.price == b.price) {
        return a.kilo < b.kilo;
    } else {
        return a.price > b.price;
    }
}

int main() {
    int n;
    long long M;

    std::cin >> M;
    std::cin >> n;

    std::vector<Bunch> bunches(n);

    for (int i = 0; i < n; i++) {
        std::cin >> bunches[i].price >> bunches[i].kilo;
    }

    std::sort(bunches.begin(), bunches.end(), compare);

    long long max_summ = 0;

    for (auto bunch: bunches) {
        if (M - bunch.kilo >= 0) {
            max_summ += bunch.kilo * bunch.price;
            M -= bunch.kilo;
        } else {
            max_summ += M * bunch.price;
            break;
        }
    }

    std::cout << max_summ << std::endl;
}