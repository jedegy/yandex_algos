// https://contest.yandex.ru/contest/22449/problems/J/
#include <iostream>

void factorization(int n) {
    int i = 2;

    while (i * i <= n) {
        if (n % i == 0) {
            while (n % i == 0) {
                std::cout << i << " ";
                n /= i;
            }
        }
        i++;
    }

    if (n >= 2) {
        std::cout << n << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;
    factorization(n);

    return 0;
}
