#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int curr = i;
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

void inputArray(vector<int> &arr)
{
    cout << "Enter elements: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void printArray(vector<int> &arr)
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
    cout << "enter number of elements: ";
    cin >> n;
    vector<int> arr(n);

    inputArray(arr);
    insertionSort(arr);
    printArray(arr);

    return 0;
}