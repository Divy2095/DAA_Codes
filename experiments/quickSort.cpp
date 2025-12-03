#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int idx = low - 1;
    int pivot = arr[high];
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[high], arr[idx]); // why we can't write pivot in place of arr[high]?
    return idx;
}
void quickSort(vector<int> &arr, int low, int high)
{
    // pivIdx is the correct position of the pivot element
    if (low < high)
    {
        // Find pivot index after partitioning
        int pivIdx = partition(arr, low, high);

        // Recursively sort elements before and after pivot
        quickSort(arr, low, pivIdx - 1);
        quickSort(arr, pivIdx + 1, high);
    }
}

void fill_array(vector<int> &arr)
{
    cout << "enter array elements: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print_array(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "enter the size of array: ";
    cin >> n;
    vector<int> arr(n);

    int low = 0;
    int high = n - 1;

    fill_array(arr);
    quickSort(arr, 0, n - 1);
    print_array(arr);
}