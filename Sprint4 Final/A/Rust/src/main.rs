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
*/

use std::collections::{HashMap, HashSet};
use std::io::{self, BufRead};

/// Represents a document, with its words and their occurrence counts.
#[derive(Default, Clone)]
struct Document {
    words: HashMap<String, usize>,
}

impl Document {
    /// Increment the occurrence count of a word in the document.
    ///
    /// # Arguments
    ///
    /// * `word` - The word to increment the occurrence count of.
    fn add_word(&mut self, word: &str) {
        *self.words.entry(word.to_string()).or_insert(0) += 1;
    }

    /// Get the occurrence counts of all words in the document.
    ///
    /// # Returns
    ///
    /// A reference to the map of words and their occurrence counts.
    fn get_words(&self) -> &HashMap<String, usize> {
        &self.words
    }
}

/// Represents relevance information of a document.
struct Relevance {
    doc_id: usize,
    relevance_count: usize,
}

impl Relevance {
    /// Create a new relevance information instance.
    ///
    /// # Arguments
    ///
    /// * `doc_id` - The ID of the document.
    /// * `relevance_count` - The relevance count of the document.
    fn new(doc_id: usize, relevance_count: usize) -> Self {
        Self {
            doc_id,
            relevance_count,
        }
    }
}

/// Represents a search engine, with documents and an index.
struct SearchEngine {
    docs: Vec<Document>,
    index: HashMap<String, Vec<(usize, usize)>>,
}

impl SearchEngine {
    /// Create a new search engine with the given number of documents.
    ///
    /// # Arguments
    ///
    /// * `n` - The number of documents.
    fn new(n: usize) -> Self {
        Self {
            docs: vec![Document::default(); n],
            index: HashMap::new(),
        }
    }

    /// Split a string into words by whitespace.
    ///
    /// # Arguments
    ///
    /// * `s` - The string to split.
    ///
    /// # Returns
    ///
    /// A vector of words.
    fn split_whitespace(s: &str) -> Vec<&str> {
        s.split_whitespace().collect()
    }

    /// Process a document, add its words and update the index.
    ///
    /// # Arguments
    ///
    /// * `id` - The ID of the document.
    /// * `text` - The text of the document.
    fn process_document(&mut self, id: usize, text: &str) {
        let words = Self::split_whitespace(text);
        for word in words {
            self.docs[id - 1].add_word(word);
        }

        let word_count = self.docs[id - 1].get_words();
        for (word, count) in word_count {
            self.index
                .entry(word.to_string())
                .or_insert_with(Vec::new)
                .push((id, *count));
        }
    }

    /// Process a query, calculate relevance and output the top results.
    ///
    /// # Arguments
    ///
    /// * `query` - The query string.
    fn process_query(&self, query: &str) {
        let query_words_vec = Self::split_whitespace(query);
        let query_words: HashSet<_> = query_words_vec.iter().cloned().collect();

        let mut relevance = HashMap::new();
        for word in query_words {
            if let Some(docs) = self.index.get(word) {
                for (doc_id, count) in docs {
                    *relevance.entry(*doc_id).or_insert(0) += count;
                }
            }
        }

        let mut relevance_vec: Vec<_> = relevance
            .into_iter()
            .map(|(doc_id, count)| Relevance::new(doc_id, count))
            .collect();
        relevance_vec.sort_by(|a, b| b.relevance_count.cmp(&a.relevance_count).then(a.doc_id.cmp(&b.doc_id)));

        for rel in relevance_vec.iter().take(5) {
            print!("{} ", rel.doc_id);
        }
        println!();
    }
}

fn main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();

    let n: usize = lines.next().unwrap()?.trim().parse().unwrap();
    let mut search_engine = SearchEngine::new(n);

    for i in 1..=n {
        let line = lines.next().unwrap()?;
        search_engine.process_document(i, &line);
    }

    let m: usize = lines.next().unwrap()?.trim().parse().unwrap();
    for _ in 0..m {
        let line = lines.next().unwrap()?;
        search_engine.process_query(&line);
    }

    Ok(())
}
