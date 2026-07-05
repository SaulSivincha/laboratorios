#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    srand(time(0));
    vector<int> arr(10);
    for (int i = 0; i < 10; i++) arr[i] = rand() % 100;

    cout << "Original: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    selectionSort(arr);

    cout << "Sorted: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
}
