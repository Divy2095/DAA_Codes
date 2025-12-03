#include <bits/stdc++.h>
using namespace std;

int findPreviousJob(vector<int> &start, vector<int> &finish, int currentIndex)
{
    for (int i = currentIndex - 1; i >= 0; i--)
    {
        if (finish[i] <= start[currentIndex])
        {
            return i;
        }
    }
    return -1;
}

int jobScheduling(vector<int> &start, vector<int> &finish, vector<int> &profit)
{

    int n = start.size();
    vector<int> order(n);
    for (int i = 0; i < n; i++)
        order[i] = i;

    sort(order.begin(), order.end(), [&](int a, int b)
         { return finish[a] < finish[b]; });
    vector<int> s(n), f(n), p(n);
    for (int i = 0; i < n; i++)
    {
        s[i] = start[order[i]];
        f[i] = finish[order[i]];
        p[i] = profit[order[i]];
    }
    vector<int> dp(n);
    dp[0] = p[0];

    for (int i = 1; i < n; i++)
    {
        int include = p[i];
        int prev = findPreviousJob(s, f, i);

        if (prev != -1)
            include += dp[prev];
        int exclude = dp[i - 1];
        dp[i] = max(include, exclude);
    }

    return dp[n - 1];
}

int main()
{
    vector<int> start = {1, 3, 6, 2};
    vector<int> finish = {2, 5, 19, 100};
    vector<int> profit = {50, 20, 100, 200};

    int result = jobScheduling(start, finish, profit);

    cout << "\nMaximum Profit Possible: " << result << endl;

    return 0;
}
