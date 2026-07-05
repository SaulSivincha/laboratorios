#include <iostream>
#include <vector>
#include <thread>
#include <limits>
#include <algorithm>

using namespace std;

void findMaxInRange(const vector<int>& numbers, int start, int end, int& partialMax) {
    partialMax = numeric_limits<int>::min();

    for (int i = start; i < end; i++) {
        if (numbers[i] > partialMax) {
            partialMax = numbers[i];
        }
    }
}

int main() {
    int size = 10000000;
    vector<int> numbers(size);

    for (int i = 0; i < size; i++) {
        numbers[i] = i % 500000;
    }

    numbers[7654321] = 9999999;

    int threadCount = thread::hardware_concurrency();

    if (threadCount == 0) {
        threadCount = 4;
    }

    int blockSize = size / threadCount;

    vector<thread> threads;
    vector<int> partialMaxValues(threadCount);

    for (int i = 0; i < threadCount; i++) {
        int start = i * blockSize;
        int end = (i == threadCount - 1) ? size : start + blockSize;

        threads.emplace_back(findMaxInRange, cref(numbers), start, end, ref(partialMaxValues[i]));
    }

    for (thread& worker : threads) {
        worker.join();
    }

    int maxValue = numeric_limits<int>::min();

    for (int value : partialMaxValues) {
        maxValue = max(maxValue, value);
    }

    cout << "Array size: " << size << endl;
    cout << "Threads used: " << threadCount << endl;
    cout << "Maximum value: " << maxValue << endl;

    return 0;
}