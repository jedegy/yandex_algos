// https://contest.yandex.ru/contest/22449/problems/I/
#include <iostream>

bool is_four_degree(int n) {
    if (n == 1) {
        return true;
    }
    if (n % 4 != 0) {
        return false;
    } else {
        return is_four_degree(n >> 2);
    }
}

int main() {
    int n;
    std::cin >> n;
    if (is_four_degree(n)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }

    return 0;
}
