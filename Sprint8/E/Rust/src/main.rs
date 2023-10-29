// https://contest.yandex.ru/contest/26131/problems/E/
use std::io::BufRead;

struct Replacement {
    value: String,
    position: usize,
}

fn read_replacements(lines: &mut std::io::Lines<std::io::StdinLock>, n: usize) -> Vec<Replacement> {
    let mut replacements = Vec::with_capacity(n);
    for _ in 0..n {
        let line = lines.next().unwrap().unwrap();
        let parts: Vec<&str> = line.split_whitespace().collect();
        let replacement = Replacement {
            value: parts[0].to_string(),
            position: parts[1].parse().unwrap(),
        };
        replacements.push(replacement);
    }
    replacements.sort_by(|a, b| a.position.cmp(&b.position));
    replacements
}

fn apply_replacements(s: &str, replacements: &[Replacement]) -> String {
    let mut result = String::new();
    let mut prev = 0;
    for r in replacements {
        result.push_str(&s[prev..r.position]);
        result.push_str(&r.value);
        prev = r.position;
    }
    result.push_str(&s[prev..]);
    result
}

fn main() {
    let mut lines = std::io::stdin().lock().lines();
    let s = lines.next().unwrap().unwrap();
    let n: usize = lines.next().unwrap().unwrap().parse().unwrap();

    let replacements = read_replacements(&mut lines, n);
    println!("{}", apply_replacements(&s, &replacements));
}
