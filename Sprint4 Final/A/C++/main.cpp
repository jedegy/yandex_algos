/*
-- WORKING PRINCIPLE --
This program implements a search engine for a set of documents.
Each document is processed to extract words and their occurrence count.
Queries can then be submitted to the search engine, and the program will output a list of document IDs that contain the words in the query.
The results are sorted by their relevance to the query based on the occurrence of the query words in the documents.

-- PROOF OF CORRECTNESS --
The program processes each document by tokenizing the text into words, which are then stored in an index along with their occurrence counts in each document.
When a query is submitted, the search engine computes the relevance of each document based on the words in the query and their occurrence count in the documents.
The `Relevance` struct is used to sort documents by their relevance, and the `compare` function takes into account the document's relevance count.
The search engine returns the document IDs sorted by their relevance.

-- TIME COMPLEXITY --
1. The average time complexity for processing each document is `O(N)` where `N` is the number of words in the document.
2. The average time complexity for processing a query is `O(Q + K * log(K))` where `Q` is the number of words in the query
 and `K` is the number of documents returned by the query.
The sort operation is the most time-consuming step in processing a query and has a time complexity of O(k * log(k)),
 where k is the number of documents returned by the query.
3. Hash map operations take on average O(1).

-- SPACE COMPLEXITY --
The space complexity of the program is O(d * m) where d is the number of documents and m is the average number of unique
 words in a document.
This is because each document's words are stored in a hash map, and an index is maintained that maps words to document
 IDs and their occurrence counts.

Link to successful report: https://contest.yandex.ru/contest/24414/run-report/89726754/
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// Class representing a document, with its words and their occurrence counts.
class Document {
private:
    // Map of words and their occurrence counts
    unordered_map<string, int> words;

public:
    // Increment the occurrence count of a word in the document.
    void add_word(const string &word) {
        words[word]++;
    }

    // Get the occurrence counts of all words in the document.
    const unordered_map<string, int>& get_words() const {
        return words;
    }
};

// Structure representing relevance information of a document.
struct Relevance {
    // ID of the document
    int doc_id;
    // Relevance count of the document
    int relevance_count;

    Relevance(int doc_id, int relevance_count)
            : doc_id(doc_id), relevance_count(relevance_count) {}

    // Comparator for sorting relevance information.
    static bool compare(const Relevance &a, const Relevance &b) {
        if (a.relevance_count == b.relevance_count) {
            return a.doc_id < b.doc_id;
        }
        return a.relevance_count > b.relevance_count;
    }
};

// Class representing a search engine, with documents and an index.
class SearchEngine {
private:
    // Vector of documents
    vector<Document> docs;
    // Index map of words to document IDs and occurrence counts
    unordered_map<string, set<pair<int, int>>> index;

    // Static helper function to split a string into words by whitespace.
    static vector<string> split_whitespace(const string &s) {
        istringstream iss(s);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    }

public:
    // Constructor taking the number of documents as input.
    explicit SearchEngine(int n) : docs(n) {}

    // Process a document, add its words and update the index.
    void process_document(int id, const string &text) {
        vector<string> words = split_whitespace(text);
        for (const auto &word: words) {
            docs[id-1].add_word(word);
        }

        const unordered_map<string, int>& word_count = docs[id-1].get_words();
        for (const auto& wc: word_count) {
            index[wc.first].emplace(id, wc.second);
        }
    }

    // Process a query, calculate relevance and output the top results.
    void process_query(const string &query) const {
        vector<string> query_words_vec = split_whitespace(query);
        unordered_set<string> query_words(query_words_vec.begin(), query_words_vec.end());

        unordered_map<int, int> relevance;
        for (const auto &word: query_words) {
            auto it = index.find(word);
            if (it != index.end()) {
                for (const auto &doc: it->second) {
                    relevance[doc.first] += doc.second;
                }
            }
        }

        vector<Relevance> relevance_vec;
        for (const auto &rel: relevance) {
            relevance_vec.emplace_back(rel.first, rel.second);
        }
        sort(relevance_vec.begin(), relevance_vec.end(), Relevance::compare);

        for (int i = 0; i < min(5, static_cast<int>(relevance_vec.size())); ++i) {
            cout << relevance_vec[i].doc_id << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();

    SearchEngine searchEngine(n);
    for (int i = 1; i <= n; ++i) {
        string line;
        getline(cin, line);
        searchEngine.process_document(i, line);
    }

    int m;
    cin >> m;
    cin.ignore();

    for (int i = 0; i < m; ++i) {
        string line;
        getline(cin, line);
        searchEngine.process_query(line);
    }

    return 0;
}
