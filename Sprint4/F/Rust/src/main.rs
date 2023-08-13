// https://contest.yandex.ru/contest/23991/problems/F/

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let _: usize = input.trim().parse().unwrap();

    let mut map: std::collections::BTreeMap<String, Vec<usize>> = std::collections::BTreeMap::new();

    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    let words: Vec<String> = line
        .trim()
        .split_whitespace()
        .map(|x| x.to_string())
        .collect();

    for (index, word) in words.iter().enumerate() {
        let mut chars: Vec<char> = word.chars().collect();
        chars.sort();
        let key: String = chars.into_iter().collect();

        map.entry(key).or_default().push(index);
    }

    let mut result: Vec<(usize, Vec<usize>)> = Vec::new();
    for (_, vec) in &map {
        if !vec.is_empty() {
            result.push((vec[0], vec.clone()));
        }
    }

    result.sort();

    for t in &result {
        for &elem in &t.1 {
            print!("{} ", elem);
        }
        println!();
    }
}
