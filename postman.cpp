#include <iostream>
using namespace std;

void postmanSort(int arr[], int n) {
    // Find max value
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal) maxVal = arr[i];

    // Find number of digits in max value
    int digits = 0;
    int temp = maxVal;
    while (temp > 0) { digits++; temp /= 10; }

    int exp = 1;
    int* output = new int[n];

    for (int d = 0; d < digits; d++) {
        int count[10] = {0};

        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[--count[digit]] = arr[i];
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];

        exp *= 10;
    }

    delete[] output;
}

int main() {
    int n;

    cout << "How many numbers would you like to sort? ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        cout << "Number " << (i + 1) << ": ";
        cin >> arr[i];
    }

    cout << "\nBefore sorting: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    postmanSort(arr, n);

    cout << "After sorting:  ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}
