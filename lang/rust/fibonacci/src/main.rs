use std::io;

fn main() {
    let mut n = String::new();

    println!("n: ");

    io::stdin()
        .read_line(&mut n)
        .expect("Failed to read line");

    let n: u32 = match n.trim().parse() {
        Ok(num) => num,
        Err(_) => 0
    };

    let mut prev: usize = 0;
    let mut cur: usize = 1;

    // println!("{prev}");
    for _ in 1..n {
        let next = prev + cur;
        prev = cur;
        cur = next;
        // println!("{cur}");
    };


    println!("The {n}th fibonacci is: {cur}");
}
