// https://contest.yandex.ru/contest/23991/problems/I/
#include <iostream>
#include <vector>
#include <set>

const long long base1 = 257, mod1 = 1e9 + 7;
const long long base2 = 263, mod2 = 1e9 + 9;

long long powmod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void prefix_hashes(const std::vector<int>& arr, std::vector<long long>& prefHash, long long base, long long mod) {
    long long hash = 0;
    for (int i = 0; i < arr.size(); i++) {
        hash = (hash * base + arr[i]) % mod;
        prefHash[i] = hash;
    }
}

std::pair<long long, long long> poly_hash(const std::vector<long long>& prefix_hashes_1, const std::vector<long long>& prefix_hashes_2, int start, int len) {
    long long hash1 = prefix_hashes_1[start + len - 1];
    if (start) {
        hash1 = (hash1 - prefix_hashes_1[start - 1] * powmod(base1, len, mod1) % mod1 + mod1) % mod1;
    }

    long long hash2 = prefix_hashes_2[start + len - 1];
    if (start) {
        hash2 = (hash2 - prefix_hashes_2[start - 1] * powmod(base2, len, mod2) % mod2 + mod2) % mod2;
    }

    return {hash1, hash2};
}

bool check(const std::vector<int>& vec1, const std::vector<int>& vec2, int len) {
    std::set<std::pair<long long, long long>> set;

    std::vector<long long> pref_hashes_1A(vec1.size()), pref_hashes_1B(vec1.size());
    std::vector<long long> pref_hashes_2A(vec2.size()), pref_hashes_2B(vec2.size());

    prefix_hashes(vec1, pref_hashes_1A, base1, mod1);
    prefix_hashes(vec1, pref_hashes_1B, base2, mod2);
    prefix_hashes(vec2, pref_hashes_2A, base1, mod1);
    prefix_hashes(vec2, pref_hashes_2B, base2, mod2);

    for (int i = 0; i <= vec1.size() - len; i++) {
        set.insert(poly_hash(pref_hashes_1A, pref_hashes_1B, i, len));
    }

    for (int i = 0; i <= vec2.size() - len; i++) {
        if (set.find(poly_hash(pref_hashes_2A, pref_hashes_2B, i, len)) != set.end()) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> scores_1(n);
    for (int i = 0; i < n; i++) {
        std::cin >> scores_1[i];
    }

    std::cin >> m;
    std::vector<int> scores_2(m);
    for (int i = 0; i < m; i++) {
        std::cin >> scores_2[i];
    }

    int result = 0;
    int left = 0, right = std::min(n, m);

    while (left <= right) {
        int mid = (left + right) / 2;

        if (check(scores_1, scores_2, mid)) {
            result = std::max(mid, result);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    std::cout << result << std::endl;
    return 0;
}
