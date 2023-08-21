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
2. The average time complexity for processing a query is `O(Q)` where `Q` is the number of words in the query.
3. Hash map operations take on average O(1).

-- SPACE COMPLEXITY --
The space complexity of the program is O(M) where M is the average number of unique words in a document.
This is because each document's words are stored in a hash map, and an index is maintained that maps words to document
 IDs and their occurrence counts.

Link to successful report: https://contest.yandex.ru/contest/24414/run-report/89754639/
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iterator>

using namespace std;

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
    // Index map of words to document IDs and occurrence counts
    unordered_map<string, set<pair<int, int>>> index;
public:
    // Process a document, add its words and update the index.
    void process_document(int id, const string &text) {
        istringstream iss(text);
        istream_iterator<string> start(iss);
        istream_iterator<string> end;

        unordered_map<string, int> word_count;

        while (start != end) {
            word_count[*start]++;
            start++;
        }

        for (const auto& wc: word_count) {
            index[wc.first].emplace(id, wc.second);
        }
    }

    // Process a query, calculate relevance and output the top results.
    void process_query(const string &query) const {
        istringstream iss(query);
        istream_iterator<string> start(iss);
        istream_iterator<string> end;

        unordered_set<string> query_words;

        while (start != end) {
            query_words.insert(*start);
            start++;
        }

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
        partial_sort(relevance_vec.begin(), relevance_vec.begin() + min(5, static_cast<int>(relevance_vec.size())),
                     relevance_vec.end(), Relevance::compare);

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

    SearchEngine searchEngine;
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
