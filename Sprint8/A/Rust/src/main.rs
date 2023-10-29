// https://contest.yandex.ru/contest/26131/problems/A/

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    let parts: Vec<&str> = input.trim().split_whitespace().collect();

    for part in parts.iter().rev() {
        print!("{} ", part);
    }

    println!();
}
