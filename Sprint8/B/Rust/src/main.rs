// https://contest.yandex.ru/contest/26131/problems/B/
use std::io::BufRead;

fn can_transform(source: &str, target: &str) -> bool {
    let diff = source.len() as isize - target.len() as isize;

    if diff.abs() > 1 {
        return false;
    }

    let mut source_chars = source.chars();
    let mut target_chars = target.chars();
    let mut change_allowed = true;

    loop {
        match (source_chars.next(), target_chars.next()) {
            (Some(sc), Some(tc)) if sc == tc => continue,
            (Some(_), Some(_)) if change_allowed => {
                change_allowed = false;
                if diff == 0 {
                    continue;
                } else if diff == 1 {
                    source_chars.next();
                    continue;
                } else if diff == -1 {
                    target_chars.next();
                    continue;
                }
            }
            (Some(_), None) if diff == 1 && change_allowed => return true,
            (None, Some(_)) if diff == -1 && change_allowed => return true,
            (None, None) => return true,
            _ => return false,
        }
    }
}

fn main() {
    let mut lines = std::io::stdin().lock().lines();

    let passport_name = lines.next().unwrap().unwrap();
    let base_name = lines.next().unwrap().unwrap();

    match can_transform(&passport_name, &base_name) {
        true => println!("OK"),
        false => println!("FAIL"),
    }
}
