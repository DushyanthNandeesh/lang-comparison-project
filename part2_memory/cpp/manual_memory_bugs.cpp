// C++: intentionally buggy manual memory management, for profiling with Valgrind.
// Demonstrates (1) a memory LEAK and (2) a DANGLING POINTER / use-after-free.
#include <iostream>

int* allocateArray(int size, int fillValue) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = fillValue;
    return arr;
}

int main() {
    // Bug 1: memory leak -- allocated but never delete[]'d.
    int* leaked = allocateArray(5, 1);
    std::cout << "Allocated 'leaked' array, never freed: " << leaked[0] << std::endl;

    // Bug 2: dangling pointer -- freed, then used again.
    int* danger = allocateArray(5, 2);
    delete[] danger;
    std::cout << "Use-after-free (undefined behavior): " << danger[0] << std::endl;

    return 0;
}
