// https://contest.yandex.ru/contest/22779/problems/L/
#include <iostream>
#include <cmath>

int fibonacci(int n, int k) {
    int f0 = 1, f1 = 1;
    int fn = 0;

    if (n == 1 || !n) {
        return 1;
    }

    for (int i = 2; i <= n; i++) {
        fn = (f0 + f1) % (int)pow(10, k);
        f0 = f1;
        f1 = fn;
    }

    return fn;
}

int main() {
    int n, k;
    std::cin >> n;
    std::cin >> k;

    std::cout << fibonacci(n, k) << std::endl;
}