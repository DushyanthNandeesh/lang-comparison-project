# Language Analysis Assignment

Code accompanying the report "Comparative Analysis of Syntax, Semantics, and
Memory Management Across Programming Languages."

## Structure

```
part1_syntax_semantics/
  section1/
    python/sum_buggy.py            # original snippet with syntax errors (Listing 1)
    javascript/sum_buggy.js        # original snippet with syntax errors (Listing 2)
    cpp/sum_buggy.cpp              # original snippet with syntax errors (Listing 3)
    python_fixed/sum_fixed.py      # corrected version
    javascript_fixed/sum_fixed.js  # corrected version
    cpp_fixed/sum_fixed.cpp        # corrected version
  section2/
    type_and_scope.py              # dynamic typing, closures, duck typing
    type_and_scope.js              # dynamic typing, coercion, var vs let scope
    type_and_scope.cpp             # static typing, lambda closures, capture modes

part2_memory/
  rust/
    ownership_demo.rs              # ownership & borrowing (compiles & runs)
    ownership_error_demo.rs        # intentional use-after-move (compile-time error)
    bench.rs                       # matched allocate/sum/drop benchmark
  java/
    GcDemo.java                    # garbage collection demo with -verbose:gc
    Bench.java                     # matched allocate/sum/null benchmark
  cpp/
    manual_memory_correct.cpp      # correct new[]/delete[] usage
    manual_memory_bugs.cpp         # intentional leak + dangling pointer
    bench.cpp                      # matched allocate/sum/free benchmark

logs/                              # captured terminal output from every run above
```

## How to run

- Python: `python3 <file>.py`
- JavaScript: `node <file>.js`
- C++: `g++ -std=c++17 -Wall <file>.cpp -o out && ./out`
- Rust: `rustc -O <file>.rs -o out && ./out`
- Java: `javac <File>.java && java -cp . <ClassName>`

Memory profiling used [Valgrind](https://valgrind.org/) (`valgrind --leak-check=full`)
for the C++ programs and the JVM's built-in `-verbose:gc` flag plus
`/usr/bin/time -v` for peak resident set size comparisons across all three
memory-management languages.
