#include <iostream>
#include <vector>

using namespace std;

void generatePermutations(const vector<int>& numbers, vector<int>& currentPermutation, vector<bool>& usedNumbers) {
    if (currentPermutation.size() == numbers.size()) {
        for (size_t index = 0; index < currentPermutation.size(); index++) {
            if (index > 0) {
                cout << " ";
            }
            cout << currentPermutation[index];
        }
        cout << endl;
        return;
    }

    for (size_t index = 0; index < numbers.size(); index++) {
        if (!usedNumbers[index]) {
            usedNumbers[index] = true;
            currentPermutation.push_back(numbers[index]);
            generatePermutations(numbers, currentPermutation, usedNumbers);
            currentPermutation.pop_back();
            usedNumbers[index] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers;
    for (int number = 1; number <= n; number++) {
        numbers.push_back(number);
    }

    vector<int> currentPermutation;
    vector<bool> usedNumbers(n, false);

    generatePermutations(numbers, currentPermutation, usedNumbers);

    return 0;
}
