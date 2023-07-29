// https://contest.yandex.ru/contest/22779/problems/K/
#include <iostream>

int fibonacci(int n) {
    if (n == 0 || n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    std::cin >> n;
    std::cout << fibonacci(n) << std::endl;
}