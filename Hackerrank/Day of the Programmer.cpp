#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    if(year == 1918) {
        return "26.09.1918";
    }
    int remFour = year % 4;
    int remHund = year % 100;
    int remFourHund = year % 400;
    string yy = to_string(year);
    string ddmmyy;
    string ddmm = "12.09.";
    
    if(year > 1918) {
        if((remFour == 0 && remHund != 0) || (remHund == 0 && remFourHund == 0)) {
            ddmmyy = ddmm+yy;
            return ddmmyy;
        }
    } else if(remFour == 0 ) {
        ddmmyy = ddmm+(yy);
        return ddmmyy;
    }
    return "13.09."+yy;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
