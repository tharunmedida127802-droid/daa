#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Linear Search Function
int linearSearch(const vector<int> &arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search Function
int binarySearch(const vector<int> &arr, int key)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (arr[middle] == key)
            return middle;
        else if (arr[middle] < key)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return -1;
}

int main()
{
    // Changed array size
    int n = 50000;
    vector<int> arr(n);

    // Fill sorted array
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    int key;
    cout << "Enter number to search: ";
    cin >> key;

    int result;

    // Linear Search
    auto startTime = high_resolution_clock::now();
    result = linearSearch(arr, key);
    auto endTime = high_resolution_clock::now();

    cout << "\n===== Linear Search =====\n";

    if (result >= 0)
        cout << "Found at Index : " << result << endl;
    else
        cout << "Element Not Found" << endl;

    cout << "Execution Time : "
         << duration_cast<microseconds>(endTime - startTime).count()
         << " microseconds\n";

    // Binary Search
    startTime = high_resolution_clock::now();
    result = binarySearch(arr, key);
    endTime = high_resolution_clock::now();

    cout << "\n===== Binary Search =====\n";

    if (result >= 0)
        cout << "Found at Index : " << result << endl;
    else
        cout << "Element Not Found" << endl;

    cout << "Execution Time : "
         << duration_cast<microseconds>(endTime - startTime).count()
         << " microseconds\n";

    return 0;
}
