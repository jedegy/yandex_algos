// https://contest.yandex.ru/contest/25596/problems/D/
#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << "0" << std::endl;
        return 0;
    }

    std::vector<int> fibonacci(n + 1);
    fibonacci[0] = 1;
    fibonacci[1] = 1;

    for (int i = 2; i <= n; i++) {
        fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % MOD;
    }

    std::cout << fibonacci[n] << std::endl;

    return 0;
}
