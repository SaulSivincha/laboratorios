#include <iostream>
#include <vector>
#include <thread>

using namespace std;

void sumRange(const vector<int>& numbers, int start, int end, long long& partialSum) {
    partialSum = 0;

    for (int i = start; i < end; i++) {
        partialSum += numbers[i];
    }
}

int main() {
    vector<int> numbers = {10, 20, 30, 40, 50, 60, 70, 80};

    int threadCount = 4;
    int size = numbers.size();
    int blockSize = size / threadCount;

    vector<thread> threads;
    vector<long long> partialSums(threadCount);

    for (int i = 0; i < threadCount; i++) {
        int start = i * blockSize;
        int end = (i == threadCount - 1) ? size : start + blockSize;

        threads.emplace_back(sumRange, cref(numbers), start, end, ref(partialSums[i]));
    }

    for (thread& worker : threads) {
        worker.join();
    }

    long long totalSum = 0;

    for (long long partialSum : partialSums) {
        totalSum += partialSum;
    }

    cout << "Array size: " << size << endl;
    cout << "Threads used: " << threadCount << endl;
    cout << "Total sum: " << totalSum << endl;

    return 0;
}