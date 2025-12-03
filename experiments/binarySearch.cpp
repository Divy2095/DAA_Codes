#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int k)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

void inputArr(vector<int> &arr)
{
    cout << "enter the array elements: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    int n;
    cout << "enter the size: ";
    cin >> n;
    vector<int> arr(n);
    inputArr(arr);

    sort(arr.begin(), arr.end());

    int k;
    cout << "element to be found: ";
    cin >> k;
    int ans = binarySearch(arr, k);
    cout << "the element is found at index: " << ans;
    return 0;
}