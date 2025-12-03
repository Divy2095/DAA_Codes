#include <bits/stdc++.h>
using namespace std;

int secondlargest(vector<int> &arr)
{
    int largest = 0;
    int seclargest = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > seclargest)
        {
            largest = arr[i];
            seclargest = largest;
        }
        if (arr[i] > seclargest && arr[i] < largest)
        {
            seclargest = arr[i];
        }
    }
    return seclargest;
}

void fill_array(vector<int> arr)
{
    for (int ele : arr)
    {
        cin >> ele;
    }
}

int main()
{
    int n;
    cout << "enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    fill_array(arr);
    int second = secondlargest(arr);
    cout << second;
    return 0;
}