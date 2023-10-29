// https://contest.yandex.ru/contest/26131/problems/J/
use std::collections::HashMap;
use std::io::BufRead;

struct TrieNode {
    children: HashMap<char, Box<TrieNode>>,
    words: Vec<String>,
}

impl TrieNode {
    fn new() -> Self {
        TrieNode {
            children: HashMap::new(),
            words: Vec::new(),
        }
    }

    fn insert(&mut self, word: &str) {
        let mut node = self;
        for ch in word.chars() {
            if ch.is_uppercase() {
                node = node
                    .children
                    .entry(ch)
                    .or_insert_with(|| Box::new(TrieNode::new()));
            }
        }
        node.words.push(word.to_string());
    }

    pub fn search(&self, request: &str) -> Vec<String> {
        let mut node = self;
        let mut result = Vec::new();

        for ch in request.chars() {
            if let Some(child) = node.children.get(&ch) {
                node = child;
            } else {
                return vec!["".to_string()];
            }
        }

        node.build_search_result(&mut result);
        result.sort_unstable();
        result
    }

    fn build_search_result(&self, result: &mut Vec<String>) {
        result.extend_from_slice(&self.words);
        for child in self.children.values() {
            child.build_search_result(result);
        }
    }
}

fn main() {
    let mut lines = std::io::stdin().lock().lines();

    let n: usize = lines.next().unwrap().unwrap().parse().unwrap();
    let mut root = TrieNode::new();
    for _ in 0..n {
        let word = lines.next().unwrap().unwrap();
        root.insert(&word);
    }

    let m: usize = lines.next().unwrap().unwrap().parse().unwrap();
    let requests: Vec<String> = (0..m).map(|_| lines.next().unwrap().unwrap()).collect();

    for request in &requests {
        let results = root.search(request);
        for word in results {
            println!("{}", word);
        }
    }
}
