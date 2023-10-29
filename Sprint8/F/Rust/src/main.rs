// https://contest.yandex.ru/contest/26131/problems/F/
use std::io::BufRead;

const MOD: i64 = 1e9 as i64 + 7;
const P: i64 = 256;

fn poly_hash(s: &str) -> i64 {
    s.chars()
        .fold((0, 1), |(hash, p_pow), c| {
            (
                (hash + (c as i64 - 'a' as i64 + 1) * p_pow) % MOD,
                (p_pow * P) % MOD,
            )
        })
        .0
}

fn main() {
    let mut lines = std::io::stdin().lock().lines();
    let n: usize = lines.next().unwrap().unwrap().parse().unwrap();

    let mut hash_map: std::collections::HashMap<i64, i32> = std::collections::HashMap::new();

    let mut result = String::new();
    let mut max_word = 0;

    for _ in 0..n {
        let word = lines.next().unwrap().unwrap();
        let hash = poly_hash(&word);
        let entry = hash_map.entry(hash).or_insert(0);
        *entry += 1;

        if max_word <= *entry {
            if max_word < *entry
                || (max_word == *entry
                    && (word.len() < result.len() || word < result || result.is_empty()))
            {
                result = word;
            }
            max_word = *entry;
        }
    }

    println!("{}", result);
}
