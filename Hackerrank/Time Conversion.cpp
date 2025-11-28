#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string hour_string = s.substr(0,2);
    int hour = stoi(hour_string);
    size_t pos = s.find("PM");
    if(pos != string::npos) {
        if(hour + 12 < 24) {
            hour_string = to_string(hour+12);
        }
    } else {
        if(hour == 12) {
            hour_string = "00";
        }
    }
    return s.replace(0,2,hour_string).erase(s.size()-2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
