// https://contest.yandex.ru/contest/22449/problems/F/

fn is_palindrome(phrase: &str) -> bool {
    let iter = phrase
        .chars()
        .filter(|&c| c.is_alphanumeric())
        .map(|c| c.to_ascii_lowercase());
    iter.clone().eq(iter.rev())
}

fn main() {
    let mut phrase = String::new();
    std::io::stdin().read_line(&mut phrase).unwrap();

    if is_palindrome(phrase.trim()) {
        println!("True");
    } else {
        println!("False");
    }
}
