#include <bits/stdc++.h>
using namespace std;
 
string tostr(int x) {
    stringstream ss;
    if (x < 10) ss << 0;
    ss << x;
    return ss.str();
}
 
int main() {
    int hh, mm;
    cin >> hh >> mm;
 
    int cnt = 0;
    string hs = tostr(hh), ms = tostr(mm);
    for (int i = 0; i < 10; ++i) {
        mm++;
        if (mm == 60) {
            mm = 0;
            hh++;
            if (hh == 24) {
                hh = 0;
            }
        }
        string hs1 = tostr(hh), ms1 = tostr(mm);
        for (int i = 0; i < 2; ++i) {
            if (hs.at(i) != hs1.at(i)) cnt++;
            if (ms.at(i) != ms1.at(i)) cnt++;
        }
        hs = hs1;
        ms = ms1;
    }
 
    cout << cnt;
}
