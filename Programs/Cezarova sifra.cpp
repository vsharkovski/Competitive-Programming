#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int x; cin >> x;
    string s; cin >> s;
    string azbs = "abcdefghijklmnopqrstuvwxyz";
    map<char, int> azb;
    map<int, char> azb1;
    for (int i = 0; i < 26; ++i) {
        azb[azbs.at(i)] = i+1;
        azb1[i+1] = azbs.at(i);
    }
    string r = "";
    for (int i = 0; i < s.length(); ++i) {
        char c = s.at(i);
        int v = azb[c] + x;
        if (v > 26) v = 52 - v;
        r += azb1[v];
    }
    cout << r;
}