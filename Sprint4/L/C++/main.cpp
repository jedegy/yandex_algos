// https://contest.yandex.ru/contest/23991/problems/L/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstdint>

const uint64_t base = 31, mod = 0xFFFFFFFFFFFFFFFF;

uint64_t get_hash(const std::vector<uint64_t> &hashes,
                   uint64_t powers,
                   int i, int n) {
    uint64_t hash = hashes[i + n] - hashes[i] * powers % mod;
    hash = (hash % mod + mod) % mod;
    return hash;
}

int main() {
    int n, k;
    std::string s;
    std::cin >> n >> k;
    std::cin >> s;

    std::unordered_map<uint64_t, int> map;
    std::unordered_map<uint64_t, int> result;

    std::vector<uint64_t> hashes(s.size() + 1, 0);
    uint64_t powers = 1;
    for (int i = 1; i <= s.size(); ++i) {
        hashes[i] = (hashes[i - 1] * base + s[i - 1] - 'a' + 1) % mod;
        if (i <= n) {
            powers = (powers * base) % mod;
        }
    }

    for (int i = 0; i + n <= s.size(); i++) {
        auto hash = get_hash(hashes, powers, i, n);
        if (++map[hash] == 1) {
            result[hash] = i;
        }
    }

    for (auto &pair : map) {
        if (pair.second >= k) {
            std::cout << result[pair.first] << " ";
        }
    }

    return 0;
}
