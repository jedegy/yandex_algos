// https://contest.yandex.ru/contest/26131/problems/K/
use std::io::BufRead;

fn refactor(s: &str) -> String {
    let allowed_chars = "bdfhjlnprtvxz";
    s.chars().filter(|&c| allowed_chars.contains(c)).collect()
}

fn main() {
    let mut lines = std::io::stdin().lock().lines();

    let mut a = lines.next().unwrap().unwrap();
    let mut b = lines.next().unwrap().unwrap();

    a = refactor(&a);
    b = refactor(&b);

    match a.cmp(&b) {
        std::cmp::Ordering::Equal => println!("0"),
        std::cmp::Ordering::Less => println!("-1"),
        std::cmp::Ordering::Greater => println!("1"),
    }
}
