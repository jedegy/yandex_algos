/*
-- WORKING PRINCIPLE --
This program determines whether a given string can be split into words from the provided dictionary, using the
data structure Trie (trie).

-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
The correctness of the algorithm is ensured by:
 1. Building a trie from dictionary words, which provides an efficient structure for word existence check and its partitioning.
 2. Using a dynamic programming method to determine the possibility of dividing parts of the string using words from the trie.

-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
1. Trie construction: For n words with an average length of m, building the trie will take O(n * m) time.
2. String partitioning: Iterating over string T and checking all possible words from the trie leads to a time
complexity of O(len(T) * m).

 The overall time complexity is O(n * m + len(T) * m).

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
1. Trie: Storing the trie takes space proportional to the total number of characters in the dictionary, which is O(n * m).
2. Array for dynamic programming: Additional space of O(len(T)) is required to save partitioning check results for substrings.

The overall space complexity of the program is O(n * m + len(T)).

Link to successful report: https://contest.yandex.ru/contest/26133/run-report/95130121/
*/
#include <iostream>
#include <vector>
#include <string>
#include <memory>

// Power of the alphabet
const int P_ALPHABET = 26;

class Trie {
private:
    // Represents a node in a Trie structure
    struct TrieNode {
        // Children nodes for each letter of the alphabet
        std::unique_ptr<TrieNode> children[P_ALPHABET];
        // Flag to determine if this node marks the end of a word
        bool is_end_of_word = false;
    };

    // Root node of the Trie structure
    std::unique_ptr<TrieNode> root = std::make_unique<TrieNode>();

public:
    // Function inserts string to Trie structure
    void insert(const std::string& word) {
        TrieNode* current = root.get();
        for (char ch : word) {
            int index = ch - 'a';
            if (!current->children[index]) {
                current->children[index] = std::make_unique<TrieNode>();
            }
            current = current->children[index].get();
        }
        current->is_end_of_word = true;
    }

    // Function to determine if a given string can be broken down into words stored in the trie
    bool can_break(const std::string& s) {
        int len = s.size();

        std::vector<bool> dp(len + 1, false);
        dp[0] = true;

        for (int i = 0; i < len; i++) {
            if (!dp[i]) continue;

            TrieNode* current = root.get();
            for (int j = i; j < len; j++) {
                int index = s[j] - 'a';
                if (!current->children[index]) break;

                current = current->children[index].get();
                if (current->is_end_of_word) {
                    dp[j + 1] = true;
                }
            }
        }

        return dp[len];
    }
};

int main() {
    Trie trie;

    std::string T;
    std::cin >> T;

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;
        trie.insert(word);
    }

    std::cout << (trie.can_break(T) ? "YES" : "NO") << std::endl;

    return 0;
}
