#include <iostream>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <ctime>

using namespace std;

void func1() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int* arr = (int*)malloc(10000000 * sizeof(int));

    for(int n = 0; n < 10000000; ++n) {
        arr[n] = 1000000 + static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / 9000000));
    }

    int max = *max_element(arr, arr + 10000000);
    int maxrounded = round(max);

    long long total = 0;

    for (int k = 0; k < 10000000; k++) {
        total += arr[k];
    }

    free(arr);
}

void func2() {
    int* arr = (int*)malloc(10000000 * sizeof(int));

    for(int n = 0; n < 10000000; ++n) {
        arr[n] = 1000000 + static_cast<int>(rand()) / (static_cast<int>(RAND_MAX / 9000000));
    }

    long long sum = 0;

    for (int i = 0; i < 10000000; i++) {
        sum += arr[i];
    }

    int avg = sum / 10000000;

    long long sumfunc = accumulate(arr, arr + 10000000, 0LL);
    int avgfunc = sumfunc / 10000000;

    long long onetoavg = 0;

    for (int i = 1; i <= avgfunc; i++) {
        onetoavg += i;
    }

    free(arr);
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < 100; i++) {
        func1();
        func2();
    }
}
