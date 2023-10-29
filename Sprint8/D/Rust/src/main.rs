// https://contest.yandex.ru/contest/26131/problems/D/
use std::io::BufRead;

fn common_prefix_length(strs: &[String]) -> usize {
    if strs.len() == 1 {
        return strs[0].len();
    }

    let (first, last) = (strs.first().unwrap(), strs.last().unwrap());
    first
        .chars()
        .zip(last.chars())
        .take_while(|(a, b)| a == b)
        .count()
}

fn main() {
    let mut lines = std::io::stdin().lock().lines();
    let n: usize = lines.next().unwrap().unwrap().parse().unwrap();

    let mut strs = Vec::with_capacity(n);
    for _ in 0..n {
        strs.push(lines.next().unwrap().unwrap());
    }

    println!("{}", common_prefix_length(&strs));
}
