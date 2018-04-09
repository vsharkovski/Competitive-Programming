#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string azb = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s; cin >> s;
    string r = "";
    for (int i = 0; i < s.length(); ++i) {
        char c1 = s.at(i);
        if (i+1 < s.length() && c1 - '0' >= 2 && c1 - '0' <= 9) {
            char c2 = s.at(i+1);
            for (int i = 0; i < (c1 - '0'); ++i) {
                r  += c2;
            }
            i += 1;
            continue;
        }
        if (azb.find(c1) != string::npos) {
            r += c1;
        }
    }
    cout << r << endl;
}