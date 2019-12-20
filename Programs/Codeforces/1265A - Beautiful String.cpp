#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                char pr = i == 0 ? 'z' : s[i-1];
                char nx = i+1 == n ? 'z' : s[i+1];
                for (char ch = 'a'; ch <= 'c'; ++ch) {
                    if (ch != pr && (nx == '?' || ch != nx)) {
                        s[i] = ch;
                        break;
                    }
                }
            }
        }
        bool good = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i-1]) {
                good = false;
                break;
            }
        }
        if (good) {
            cout << s << endl;
        } else {
            cout << "-1\n";
        }
    }
}
