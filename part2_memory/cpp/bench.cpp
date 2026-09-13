#include <iostream>
int main() {
    const int N = 5'000'000;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) arr[i] = i;
    long long sum = 0;
    for (int i = 0; i < N; i++) sum += arr[i];
    delete[] arr;
    std::cout << "sum=" << sum << std::endl;
    return 0;
}
