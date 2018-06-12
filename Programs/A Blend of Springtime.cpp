#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;
    bool a[101][3];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < s.length(); ++i) {
        int x = -1;
        if (s[i] == 'A') {
            x = 0;
        } else if (s[i] == 'B') {
            x = 1;
        } else if (s[i] == 'C') {
            x = 2;
        }
        if (x == -1) continue;
        a[i][x] = 1;
        if (i != 0) {
            a[i-1][x] = 1;
        }
        if (i != s.length()-1) {
            a[i+1][x] = 1;
        }
    }
    for (int i = 0; i < s.length(); ++i) {
//        cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << '\n';
        if (a[i][0] && a[i][1] && a[i][2]) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

}
