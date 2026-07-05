#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

using namespace std;

void binarySearchInRange(const vector<int>& numbers, int targetValue, int start, int end, atomic<int>& foundIndex) {
    int left = start;
    int right = end - 1;

    while (left <= right && foundIndex.load() == -1) {
        int middle = left + (right - left) / 2;

        if (numbers[middle] == targetValue) {
            foundIndex.store(middle);
            return;
        }

        if (numbers[middle] < targetValue) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
}

int main() {
    int size = 1000000;
    vector<int> numbers(size);

    for (int i = 0; i < size; i++) {
        numbers[i] = i * 2;
    }

    int targetValue = 765432 * 2;

    int threadCount = thread::hardware_concurrency();

    if (threadCount == 0) {
        threadCount = 4;
    }

    if (threadCount > size) {
        threadCount = size;
    }

    int blockSize = size / threadCount;

    vector<thread> threads;
    atomic<int> foundIndex(-1);

    for (int i = 0; i < threadCount; i++) {
        int start = i * blockSize;
        int end = (i == threadCount - 1) ? size : start + blockSize;

        threads.emplace_back(binarySearchInRange, cref(numbers), targetValue, start, end, ref(foundIndex));
    }

    for (thread& worker : threads) {
        worker.join();
    }

    cout << "Array size: " << size << endl;
    cout << "Threads used: " << threadCount << endl;
    cout << "Target value: " << targetValue << endl;

    if (foundIndex.load() != -1) {
        cout << "Position found: " << foundIndex.load() << endl;
    } else {
        cout << "Value not found" << endl;
    }

    return 0;
}