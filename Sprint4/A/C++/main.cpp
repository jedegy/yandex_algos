// https://contest.yandex.ru/contest/23991/problems/A/
#include <iostream>

long long poly_hash(int a, int m, std::string& s) {
    long long h = 0, power = 1;
    int n = int(s.length());
    for (int i = n - 1; i >= 0; --i) {
        h = (h + int(s[i]) * power) % m;
        power = (power * a) % m;
    }
    return h;
}

int main() {
    int a, m;
    std::string s;

    std::cin >> a >> m;
    std::cin >> s;

    std::cout << poly_hash(a, m, s) << std::endl;
}