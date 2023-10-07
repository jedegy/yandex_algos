// https://contest.yandex.ru/contest/25596/problems/B/

use std::cmp::Ordering;

struct Lesson {
    start: f64,
    end: f64,
}

impl Eq for Lesson {}

impl PartialEq<Self> for Lesson {
    fn eq(&self, other: &Self) -> bool {
        self.end == other.end && self.start == other.start
    }
}

impl Ord for Lesson {
    fn cmp(&self, other: &Self) -> Ordering {
        self.partial_cmp(other).unwrap()
    }
}

impl PartialOrd<Self> for Lesson {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        if self.end.eq(&other.end) {
            self.start.partial_cmp(&other.start)
        } else {
            self.end.partial_cmp(&other.end)
        }
    }
}

fn main() {
    let mut lines = std::io::stdin().lines();
    let n = lines.next().unwrap().unwrap().parse::<usize>().unwrap();
    let mut lessons = Vec::with_capacity(n);

    for _ in 0..n {
        let start_end = lines
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|x| x.parse::<f64>().unwrap())
            .collect::<Vec<f64>>();
        lessons.push(Lesson {
            start: start_end[0],
            end: start_end[1],
        });
    }

    lessons.sort_unstable();

    let mut result = Vec::new();
    let mut last_end = -1.0;

    for lesson in lessons {
        if lesson.start >= last_end {
            last_end = lesson.end;
            result.push(lesson);
        }
    }

    println!("{}", result.len());

    for lesson in result {
        println!("{} {}", lesson.start, lesson.end);
    }
}
