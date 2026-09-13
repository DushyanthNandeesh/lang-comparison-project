// C++: correct manual memory management with new[] / delete[]
#include <iostream>

int* allocateArray(int size, int fillValue) {
    int* arr = new int[size];       // heap allocation, programmer's responsibility
    for (int i = 0; i < size; i++) arr[i] = fillValue;
    return arr;
}

int main() {
    const int N = 5;
    int* data = allocateArray(N, 7);

    long sum = 0;
    for (int i = 0; i < N; i++) sum += data[i];
    std::cout << "Sum: " << sum << std::endl;

    delete[] data;   // manual free: required, or this memory leaks
    data = nullptr;  // defensive practice: avoid an accidental dangling pointer

    std::cout << "Memory freed manually with delete[]." << std::endl;
    return 0;
}
