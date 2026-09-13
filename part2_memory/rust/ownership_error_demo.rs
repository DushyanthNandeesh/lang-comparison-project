// Rust: this file is intentionally left BROKEN to capture a real
// borrow-checker error message for the report (use-after-move).
fn takes_ownership(data: Vec<i32>) -> i32 {
    data.iter().sum()
}

fn main() {
    let numbers = vec![1, 2, 3, 4, 5];
    let total = takes_ownership(numbers); // `numbers` moves into the function
    println!("Sum: {}", total);
    println!("{:?}", numbers); // ERROR: use after move, caught at compile time
}
