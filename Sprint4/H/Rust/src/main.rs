// https://contest.yandex.ru/contest/23991/problems/H/

use std::collections::HashMap;

fn is_equal(s: &str, t: &str) -> bool {
    if s.len() != t.len() {
        return false;
    }

    let mut s_t: HashMap<char, char> = HashMap::new();
    let mut t_s: HashMap<char, char> = HashMap::new();

    for (char_s, char_t) in s.chars().zip(t.chars()) {
        match s_t.get(&char_s) {
            Some(&mapped_char) if mapped_char != char_t => return false,
            None => {
                s_t.insert(char_s, char_t);
            }
            _ => {}
        }

        match t_s.get(&char_t) {
            Some(&mapped_char) if mapped_char != char_s => return false,
            None => {
                t_s.insert(char_t, char_s);
            }
            _ => {}
        }
    }

    true
}

fn main() {
    let mut s = String::new();
    let mut t = String::new();

    std::io::stdin().read_line(&mut s).unwrap();
    std::io::stdin().read_line(&mut t).unwrap();

    s = s.trim().to_string();
    t = t.trim().to_string();

    if is_equal(&s, &t) {
        println!("YES");
    } else {
        println!("NO");
    }
}
