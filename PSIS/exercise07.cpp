#include <iostream>
#include <vector>

using namespace std;

void generateSubsetsBySize(const vector<int>& numbers, int startIndex, vector<int>& currentSubset, int subsetSize) {
    if (currentSubset.size() == static_cast<size_t>(subsetSize)) {
        for (size_t index = 0; index < currentSubset.size(); index++) {
            if (index > 0) {
                cout << " ";
            }
            cout << currentSubset[index];
        }
        cout << endl;
        return;
    }

    for (int index = startIndex; index < static_cast<int>(numbers.size()); index++) {
        currentSubset.push_back(numbers[index]);
        generateSubsetsBySize(numbers, index + 1, currentSubset, subsetSize);
        currentSubset.pop_back();
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers;
    for (int number = 1; number <= n; number++) {
        numbers.push_back(number);
    }

    vector<int> currentSubset;
    for (int subsetSize = 1; subsetSize <= n; subsetSize++) {
        generateSubsetsBySize(numbers, 0, currentSubset, subsetSize);
    }

    return 0;
}
