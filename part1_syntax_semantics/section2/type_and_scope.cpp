// C++: static typing + lambda closures + capture-by-value vs capture-by-reference
#include <iostream>
#include <functional>
#include <string>

std::function<int(int)> makeCounter(int start) {
    int count = start;               // local variable, would normally die when the
                                      // function returns...
    return [count](int step) mutable {
        count += step;               // ...but the lambda captures it BY VALUE,
        return count;                // so each call keeps its own private copy
    };
}

int main() {
    auto counter = makeCounter(10);
    std::cout << "counter(1): " << counter(1) << std::endl; // 11
    std::cout << "counter(1): " << counter(1) << std::endl; // 12
    std::cout << "counter(5): " << counter(5) << std::endl; // 17

    // Static typing: the compiler fixes a variable's type for its whole lifetime.
    int value = 5;
    // value = "five";   // <-- would NOT compile: cannot convert const char* to int
    std::cout << "value: " << value << std::endl;

    // Capture by reference vs capture by value
    int shared = 100;
    auto byValue = [shared]() { return shared; };
    auto byRef   = [&shared]() { return shared; };
    shared = 200;
    std::cout << "byValue() still sees: " << byValue() << std::endl; // 100 (copied earlier)
    std::cout << "byRef() sees updated: " << byRef() << std::endl;   // 200 (live reference)

    // No implicit type coercion the way JS does; concatenation must be explicit
    int a = 1;
    std::string b = "1";
    std::cout << "a + std::stoi(b) = " << (a + std::stoi(b)) << std::endl; // 2, arithmetic
    std::cout << "std::to_string(a) + b = " << (std::to_string(a) + b) << std::endl; // "11"

    return 0;
}
