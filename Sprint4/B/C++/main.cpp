// https://contest.yandex.ru/contest/23991/problems/B/
#include <iostream>
#include <unordered_map>
#include <random>
#include <string>

long long poly_hash(int a, int m, std::string& s) {
    long long h = 0, power = 1;
    int n = int(s.length());
    for (int i = n - 1; i >= 0; --i) {
        h = (h + int(s[i]) * power) % m;
        power = (power * a) % m;
    }
    return h;
}

std::string generate_random_string(int length) {
    static const char alphanum[] =
            "abcdefghijklmnopqrstuvwxyz";
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(0, sizeof(alphanum) - 2);

    std::string result;
    for (int i = 0; i < length; ++i) {
        result.push_back(alphanum[dis(gen)]);
    }
    return result;
}

int main() {
    int a = 1000;
    int m = 123987123;
    std::unordered_map<long long, std::string> hashes;

    int string_length = 20;
    while (true) {
        std::string s = generate_random_string(string_length);
        long long h = poly_hash(a, m, s);

        if (hashes.find(h) != hashes.end()) {
            std::cout << "Found two strings with the same hash!" << std::endl;
            std::cout << "String 1: " << hashes[h] << std::endl;
            std::cout << "String 2: " << s << std::endl;
            std::cout << "Hash: " << h << std::endl;
            break;
        }

        hashes[h] = s;
    }
    return 0;
}