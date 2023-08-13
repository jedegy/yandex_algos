// https://contest.yandex.ru/contest/23991/problems/J/

use std::collections::{BTreeSet, HashMap};

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();

    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let s: i64 = input.trim().parse().unwrap();

    let mut arr = Vec::with_capacity(n);
    input.clear();
    std::io::stdin().read_line(&mut input).unwrap();
    arr.extend(
        input
            .trim()
            .split_whitespace()
            .map(|s| s.parse::<i64>().unwrap()),
    );

    let mut hash_pairs: HashMap<i64, Vec<(usize, usize)>> = HashMap::new();

    for i in 0..n - 1 {
        for j in i + 1..n {
            let sum = arr[i] + arr[j];
            hash_pairs.entry(sum).or_insert_with(Vec::new).push((i, j));
        }
    }

    let mut result: BTreeSet<Vec<i64>> = BTreeSet::new();

    for i in 0..n - 1 {
        for j in i + 1..n {
            let sum = arr[i] + arr[j];
            if let Some(pairs) = hash_pairs.get(&(s - sum)) {
                for &(first, second) in pairs {
                    if first != i && first != j && second != i && second != j {
                        let mut quad = vec![arr[i], arr[j], arr[first], arr[second]];
                        quad.sort_unstable();
                        result.insert(quad);
                    }
                }
            }
        }
    }

    println!("{}", result.len());
    for quad in result {
        for num in quad {
            print!("{} ", num);
        }
        println!();
    }
}
