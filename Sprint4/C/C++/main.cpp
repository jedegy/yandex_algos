// https://contest.yandex.ru/contest/23991/problems/C/
#include <iostream>
#include <vector>
#include <string>

std::vector<long long> prefix_hashes;
std::vector<long long> powers;

void pre_calc_prefix_hashes(int a, int m, std::string& s) {
    int n = int(s.length());

    prefix_hashes.resize(n + 1);
    powers.resize(n + 1);

    powers[0] = 1;
    prefix_hashes[0] = 0;
    for (int i = 1; i <= n; i++) {
        powers[i] = (powers[i - 1] * a) % m;
        prefix_hashes[i] = (prefix_hashes[i - 1] * a + int(s[i - 1])) % m;
    }
}

long long substring_poly_hash(int m, int l, int r) {
    long long result;

    if (l == 1) {
        result = prefix_hashes[r];
    } else {
        result = (prefix_hashes[r] - prefix_hashes[l - 1] * powers[r - l + 1] + m) % m;
        if (result < 0) {
            if ( std::abs(result) % m != 0 ) {
                result += ((std::abs(result) / m) + 1) * m;
                result %= m;
            } else {
                result = 0;
            }
        }
    }

    return result;
}

int main() {
    int a, m;
    std::string s;

    std::cin >> a >> m;
    std::cin >> s;
    pre_calc_prefix_hashes(a, m, s);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int l, r;
        std::cin >> l >> r;
        std::cout << substring_poly_hash(m, l, r) << std::endl;
    }

    return 0;
}
