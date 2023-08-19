// https://contest.yandex.ru/contest/23991/problems/K/
use std::collections::HashMap;
use std::io;

const BUCKET_SIZE: i32 = 20;
const OFFSET: i32 = 1e9 as i32;

#[derive(Hash, Eq, PartialEq, Clone)]
struct Point {
    x: i32,
    y: i32,
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: usize = input.trim().parse().unwrap();
    let mut subway_exits = Vec::with_capacity(n);

    for _ in 0..n {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let parts: Vec<i32> = input
            .split_whitespace()
            .map(|part| part.parse().unwrap())
            .collect();
        subway_exits.push(Point { x: parts[0], y: parts[1] });
    }

    input.clear();
    io::stdin().read_line(&mut input).unwrap();
    let m: usize = input.trim().parse().unwrap();
    let mut bus_stops = Vec::with_capacity(m);

    for _ in 0..m {
        input.clear();
        io::stdin().read_line(&mut input).unwrap();
        let parts: Vec<i32> = input
            .split_whitespace()
            .map(|part| part.parse().unwrap())
            .collect();
        bus_stops.push(Point { x: parts[0], y: parts[1] });
    }

    let mut buckets: HashMap<Point, Vec<Point>> = HashMap::new();
    for stop in &bus_stops {
        let bucket = Point {
            x: (stop.x + OFFSET) / BUCKET_SIZE,
            y: (stop.y + OFFSET) / BUCKET_SIZE,
        };
        buckets.entry(bucket).or_insert(Vec::new()).push(stop.clone());
    }

    let mut best_exit = -1;
    let mut max_bus_stops = 0;

    for (i, exit) in subway_exits.iter().enumerate() {
        let mut count = 0;

        for x in -1..=1 {
            for y in -1..=1 {
                let bucket = Point {
                    x: ((exit.x + x * BUCKET_SIZE) + OFFSET) / BUCKET_SIZE,
                    y: ((exit.y + y * BUCKET_SIZE) + OFFSET) / BUCKET_SIZE,
                };

                if let Some(stops) = buckets.get(&bucket) {
                    for stop in stops {
                        let dist_x = stop.x - exit.x;
                        let dist_y = stop.y - exit.y;

                        if dist_x * dist_x + dist_y * dist_y <= BUCKET_SIZE * BUCKET_SIZE {
                            count += 1;
                        }
                    }
                }
            }
        }

        if count > max_bus_stops {
            max_bus_stops = count;
            best_exit = i as i32;
        }
    }

    println!("{}", best_exit + 1);
}
