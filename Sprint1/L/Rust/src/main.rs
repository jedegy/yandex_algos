// https://contest.yandex.ru/contest/22449/problems/L/

use std::io;

fn main() {
    let mut alphabet = [0i16; 26];

    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    let s = s.trim();

    let mut t = String::new();
    io::stdin().read_line(&mut t).unwrap();
    let t = t.trim();

    for line in &[s, t] {
        for character in line.chars() {
            let index = (character as u8 - b'a') as usize;
            alphabet[index] += 1;
        }
    }

    if let Some((i, _)) = alphabet
        .iter()
        .enumerate()
        .find(|&(_, &count)| count % 2 != 0)
    {
        println!("{}", (i as u8 + b'a') as char);
    }
}
