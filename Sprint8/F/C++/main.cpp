// https://contest.yandex.ru/contest/26131/problems/F/
#include <iostream>
#include <string>
#include <map>

const long long MOD = 1e9 + 7;
const long long P = 256;

long long poly_hash(const std::string &s) {
    long long hash = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash = (hash + (c - 'a' + 1) * p_pow) % MOD;
        p_pow = (p_pow * P) % MOD;
    }
    return hash;
}

int main() {
    int n;
    std::cin >> n;

    std::map<long long, int> hash_map;

    std::string result;
    std::string s;
    int max_word = 0;
    long long hash = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> s;
        hash = poly_hash(s);
        hash_map[hash]++;

        if (max_word <= hash_map[hash]) {
            if ((max_word < hash_map[hash]) || ((max_word == hash_map[hash]) && (s.length() < result.length() || s.compare(result) < 0 || result.empty()))) {
                result = s;
            }
            max_word = hash_map[hash];
        }
    }

    std::cout << result << std::endl;
    return 0;
}