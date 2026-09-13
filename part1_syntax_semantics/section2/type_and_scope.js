// JavaScript: dynamic typing + closures + scope + var/let hoisting demo
function makeCounter(start = 0) {
    let count = start;          // captured by closure
    return function increment(step = 1) {
        count += step;          // no special keyword needed to mutate outer variable
        return count;
    };
}

const counter = makeCounter(10);
console.log("counter():", counter());   // 11
console.log("counter():", counter());   // 12
console.log("counter(5):", counter(5)); // 17

// Dynamic typing + implicit coercion (a JS-specific quirk)
let value = 5;
console.log("value:", value, typeof value);
value = "five";
console.log("value:", value, typeof value);
value = [5];
console.log("value:", value, typeof value);

console.log("1 + '1' =", 1 + "1");   // "11" -- number coerced to string
console.log("1 == '1' :", 1 == "1"); // true  -- loose equality coerces
console.log("1 === '1' :", 1 === "1"); // false -- strict equality does not

// var (function-scoped) vs let (block-scoped)
function scopeDemo() {
    if (true) {
        var fnScoped = "I leak out of the block";
        let blockScoped = "I stay inside the block";
    }
    console.log(fnScoped); // works: var ignores block scope
    try {
        console.log(blockScoped); // ReferenceError: block-scoped, not visible here
    } catch (e) {
        console.log("ReferenceError caught:", e.message);
    }
}
scopeDemo();
