// https://contest.yandex.ru/contest/26131/problems/J/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

struct TrieNode {
    std::map<char, TrieNode*> children;
    std::vector<std::string> words;
};

TrieNode* createNode() {
    return new TrieNode();
}

void insert(TrieNode* root, const std::string &word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (isupper(ch)) {
            if (!node->children.count(ch)) {
                node->children[ch] = createNode();
            }
            node = node->children[ch];
        }
    }

    node->words.push_back(word);
}

void build_search_result(TrieNode* current, std::vector<std::string>& result) {
    result.insert(result.begin(), current->words.begin(), current->words.end());
    for (auto entry : current->children) {
        build_search_result(entry.second, result);
    }
}

std::vector<std::vector<std::string>> search(TrieNode* root, std::vector<std::string> &requests) {
    std::vector<std::vector<std::string>> results;

    for (const auto& request: requests) {
        std::vector<std::string> result;
        TrieNode* node = root;
        bool no_found = false;

        for (char ch : request) {
            if (!node->children.count(ch)) {
                no_found = true;
                break;
            }
            node = node->children[ch];
        }
        if (no_found) {
            result.emplace_back("");
        } else {
            build_search_result(node, result);
            std::sort(result.begin(), result.end());
        }
        results.push_back(result);
    }

    return results;
}

int main() {
    int n;
    std::cin >> n;

    TrieNode* root = createNode();
    for (int i = 0; i < n; ++i) {
        std::string word;
        std::cin >> word;
        insert(root, word);
    }

    int m;
    std::cin >> m;
    std::cin.ignore();
    std::vector<std::string> requests(m);
    for (int i = 0; i < m; ++i) {
        std::string pattern;
        std::getline(std::cin, pattern);
        requests[i] = pattern;
    }

    std::vector<std::vector<std::string>> results = search(root, requests);
    for (const auto& result: results) {
        if (result.empty()) {
            std::cout << std::endl;
            continue;
        }

        for (const std::string &word : result) {
            std::cout << word << std::endl;
        }
    }

    return 0;
}
