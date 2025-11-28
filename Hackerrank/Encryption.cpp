#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    // remove spaces
    string t = "";
    for (char c : s) {
        if (c != ' ')
            t += c;
    }

    int n = t.length();
    int rows = floor(sqrt(n));
    int cols = ceil(sqrt(n));

    if (rows * cols < n)
        rows++;

    string result = "";

    // read column-wise
    for (int c = 0; c < cols; c++) {
        for (int r = 0; r < rows; r++) {
            int idx = r * cols + c;
            if (idx < n)
                result += t[idx];
        }
        if (c < cols - 1)
            result += " ";
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
