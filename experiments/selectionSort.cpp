#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int smallestIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[smallestIdx] > arr[j])
            {
                smallestIdx = j;
            }
        }
        if (i != smallestIdx)
        {
            int temp = arr[smallestIdx];
            arr[smallestIdx] = arr[i];
            arr[i] = temp;
        }
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
    selectionSort(arr);
    printArray(arr);

    return 0;
}