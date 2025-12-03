#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int i = low;
    int j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= high)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx + low] = temp[idx];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    int mid = low + (high - low) / 2;

    if (low >= high)
    {
        return;
    }
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
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
    cout << "enter size of array: ";
    cin >> n;
    vector<int> arr(n);

    fill_array(arr);
    mergeSort(arr, 0, n - 1);
    print_array(arr);
    return 0;
}