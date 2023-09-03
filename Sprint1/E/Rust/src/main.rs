// https://contest.yandex.ru/contest/22449/problems/E/

use std::io::{self, BufRead};

fn main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut stdin_lock = stdin.lock();

    let mut _l = String::new();
    stdin_lock.read_line(&mut _l)?;

    let mut line = String::new();
    stdin_lock.read_line(&mut line)?;

    let (max_word, max_len) = line
        .split_whitespace()
        .map(|s| (s, s.len()))
        .max_by_key(|&(_, len)| len)
        .unwrap_or(("", 0));

    println!("{}", max_word);
    println!("{}", max_len);

    Ok(())
}
