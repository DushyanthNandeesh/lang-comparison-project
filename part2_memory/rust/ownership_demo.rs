// Rust: ownership, borrowing, and compile-time memory safety
// No garbage collector and no manual free() -- the compiler's borrow
// checker inserts drop() calls automatically at scope exit.

fn takes_ownership(data: Vec<i32>) -> i32 {
    let sum: i32 = data.iter().sum();
    sum
    // `data` is dropped (its heap buffer freed) right here, automatically,
    // because this function owns it and no one else holds a reference.
}

fn borrows_data(data: &Vec<i32>) -> i32 {
    // Borrows a reference instead of taking ownership: the caller keeps
    // using `data` after this call returns.
    data.iter().sum()
}

fn main() {
    let numbers = vec![1, 2, 3, 4, 5]; // heap-allocated, owned by `numbers`

    let total_borrowed = borrows_data(&numbers); // immutable borrow
    println!("Sum via borrow: {}", total_borrowed);
    println!("Still usable after borrow: {:?}", numbers);

    let total_owned = takes_ownership(numbers); // ownership MOVES into the function
    println!("Sum via move: {}", total_owned);

    // The next line is commented out on purpose: `numbers` was moved above,
    // so using it again is a COMPILE-TIME error, not a runtime crash.
    // println!("{:?}", numbers); // error[E0382]: borrow of moved value: `numbers`

    // Demonstrate scoped drop and a mutable borrow
    {
        let mut boxed = Box::new(String::from("heap-allocated string"));
        boxed.push_str(" (mutated through an exclusive borrow)");
        println!("{}", boxed);
    } // `boxed` is dropped here; its heap memory is freed deterministically,
      // the instant it goes out of scope -- no GC pause, no manual free().

    println!("End of main: all heap allocations already freed.");
}
