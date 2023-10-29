// https://contest.yandex.ru/contest/26131/problems/H/
use std::io::BufRead;

fn kmp_search(text: &str, pattern: &str) -> Vec<usize> {
    let mut indexes = Vec::new();
    let combined_str = format!("{}#{}", pattern, text);
    let mut prefix_table = vec![0; combined_str.len()];
    let mut length_of_previous_prefix = 0;

    for i in 1..combined_str.len() {
        let mut j = length_of_previous_prefix;
        while j > 0 && combined_str.chars().nth(j).unwrap() != combined_str.chars().nth(i).unwrap()
        {
            j = prefix_table[j - 1];
        }
        if combined_str.chars().nth(j).unwrap() == combined_str.chars().nth(i).unwrap() {
            j += 1;
        }
        if i < pattern.len() {
            prefix_table[i] = j;
        }
        length_of_previous_prefix = j;
        if j == pattern.len() {
            indexes.push(i - 2 * pattern.len());
        }
    }

    indexes
}

fn replace_pattern(text: &str, pattern: &str, replacement: &str, matches: &[usize]) -> String {
    let mut result = String::new();
    let mut last_index = 0;

    for &match_index in matches {
        result.push_str(&text[last_index..match_index]);
        result.push_str(replacement);
        last_index = match_index + pattern.len();
    }

    result.push_str(&text[last_index..]);
    result
}

fn main() {
    let mut lines = std::io::stdin().lock().lines();

    let text = lines.next().unwrap().unwrap();
    let pattern = lines.next().unwrap().unwrap();
    let replacement = lines.next().unwrap().unwrap();

    let matches = kmp_search(&text, &pattern);
    let result = replace_pattern(&text, &pattern, &replacement, &matches);

    println!("{}", result);
}
