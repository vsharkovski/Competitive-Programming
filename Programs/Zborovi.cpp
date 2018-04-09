#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    map<char, int> bm, bg;
    for (int i = 1; i <= 26; ++i) {
        char c;
        int v;
        cin >> c >> v;
        bm[c] = v;
        bg[toupper(c)] = v + 20;
    }
    string high;
    int highv = -1;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string m; cin >> m;
        int v = 0;
        for (int i = 0; i < m.length(); ++i) {
            char c = m.at(i);
            v += bm[c] + bg[c]; //always in one but not the other
        }
        //cout << m << " " << v << endl;
        if (v > highv) {
            highv = v;
            high = m;
        }
    }
    cout << high;
}