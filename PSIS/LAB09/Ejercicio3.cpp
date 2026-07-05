#include <iostream>
#include <vector>
#include <thread>
#include <string>

using namespace std;

void countTextInRange(const vector<string>& textLines, const string& targetText, int start, int end, int& partialCount) {
    partialCount = 0;

    for (int i = start; i < end; i++) {
        size_t position = textLines[i].find(targetText);

        while (position != string::npos) {
            partialCount++;
            position = textLines[i].find(targetText, position + targetText.length());
        }
    }
}

int main() {
    int size = 1000000;
    vector<string> textLines(size);

    for (int i = 0; i < size; i++) {
        textLines[i] = "the system processes text and the text is analyzed";
    }

    string targetText = "text";

    int threadCount = thread::hardware_concurrency();

    if (threadCount == 0) {
        threadCount = 4;
    }

    int blockSize = size / threadCount;

    vector<thread> threads;
    vector<int> partialCounts(threadCount);

    for (int i = 0; i < threadCount; i++) {
        int start = i * blockSize;
        int end = (i == threadCount - 1) ? size : start + blockSize;

        threads.emplace_back(countTextInRange, cref(textLines), cref(targetText), start, end, ref(partialCounts[i]));
    }

    for (thread& worker : threads) {
        worker.join();
    }

    int totalCount = 0;

    for (int partialCount : partialCounts) {
        totalCount += partialCount;
    }

    cout << "Text lines: " << size << endl;
    cout << "Threads used: " << threadCount << endl;
    cout << "Searched text: " << targetText << endl;
    cout << "Occurrences found: " << totalCount << endl;

    return 0;
}