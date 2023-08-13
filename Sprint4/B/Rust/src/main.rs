// https://contest.yandex.ru/contest/23991/problems/B/
use rand::{distributions::Distribution, distributions::Uniform};
use std::collections::HashMap;

fn poly_hash(a: i64, m: i64, s: &str) -> i64 {
    let mut h: i64 = 0;
    let mut power: i64 = 1;
    for c in s.chars().rev() {
        h = (h + (c as i64) * power) % m;
        power = (power * a) % m;
    }
    h
}

fn generate_random_string(length: usize) -> String {
    let alphanum: &[u8] = b"abcdefghijklmnopqrstuvwxyz";
    let mut rng = rand::thread_rng();
    let range = Uniform::from(0..alphanum.len());

    (0..length)
        .map(|_| alphanum[range.sample(&mut rng)] as char)
        .collect()
}

fn main() {
    let a: i64 = 1000;
    let m: i64 = 123987123;
    let mut hashes: HashMap<i64, String> = HashMap::new();

    let string_length: usize = 20;
    loop {
        let s = generate_random_string(string_length);
        let h = poly_hash(a, m, &s);

        if let Some(existing_string) = hashes.get(&h) {
            println!("Found two strings with the same hash!");
            println!("String 1: {}", existing_string);
            println!("String 2: {}", s);
            println!("Hash: {}", h);
            break;
        }

        hashes.insert(h, s);
    }
}
