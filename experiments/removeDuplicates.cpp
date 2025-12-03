#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr)
{
    int i = 0;
    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i + 1] = arr[j];
        }
    }
    return i + 1;
}

void fill_array(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    int n;
    cout << "enter array size: ";
    cin >> n;
    vector<int> arr(n);
    fill_array(arr);
    int res = removeDuplicates(arr);
    for (int i = 0; i < res; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}