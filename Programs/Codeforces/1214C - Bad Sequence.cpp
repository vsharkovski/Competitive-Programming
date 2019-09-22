#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    if (n % 2 != 0) {
        cout << "No\n";
        return 0;
    }
    for (int I = 0; I < 2; ++I) {
        int bal = 0, minbal = 1e9;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') bal += 1;
            else bal -= 1;
            minbal = min(minbal, bal);
        }
        if (minbal >= -1 && bal == 0) {
            cout << "Yes\n";
            return 0;
        }
        if (!I) {
            for (int i = 0; i < n; ++i) {
                if (s[i] == '(') {
                    s[i] = ')';
                } else {
                    s[i] = '(';
                }
            }
            reverse(s.begin(), s.end());
        }
    }
    cout << "No\n";
}
