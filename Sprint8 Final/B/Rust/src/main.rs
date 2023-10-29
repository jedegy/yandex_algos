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
*/
use std::io::BufRead;

const P_ALPHABET: usize = 26;

struct TrieNode {
    children: [Option<Box<TrieNode>>; P_ALPHABET],
    is_end_of_word: bool,
}

impl TrieNode {
    fn new() -> Self {
        TrieNode {
            children: Default::default(),
            is_end_of_word: false,
        }
    }
}

struct Trie {
    root: TrieNode,
}

impl Trie {
    fn new() -> Self {
        Trie {
            root: TrieNode::new(),
        }
    }

    fn insert(&mut self, word: &str) {
        let mut current = &mut self.root;
        for ch in word.chars().map(|ch| (ch as usize) - ('a' as usize)) {
            current = current.children[ch].get_or_insert_with(|| Box::new(TrieNode::new()));
        }
        current.is_end_of_word = true;
    }

    fn can_break(&self, s: &str) -> bool {
        let len = s.len();
        let mut dp = vec![false; len + 1];
        dp[0] = true;

        for i in 0..len {
            if !dp[i] {
                continue;
            }

            let mut current = &self.root;
            for (j, &ch) in s[i..].as_bytes().iter().enumerate() {
                let index = (ch as usize) - ('a' as usize);
                match &current.children[index] {
                    Some(child) => current = child,
                    None => break,
                }

                if current.is_end_of_word {
                    dp[i + j + 1] = true;
                }
            }
        }

        dp[len]
    }
}

fn main() {
    let mut trie = Trie::new();

    let mut lines = std::io::stdin().lock().lines();
    let target = lines.next().unwrap().unwrap();

    let n: usize = lines.next().unwrap().unwrap().parse().unwrap();

    for _ in 0..n {
        let word = lines.next().unwrap().unwrap();
        trie.insert(&word);
    }

    println!("{}", if trie.can_break(&target) { "YES" } else { "NO" });
}
