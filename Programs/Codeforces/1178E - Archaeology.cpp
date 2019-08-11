#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s, t = "";
    cin >> s;
    int l = 0, r = s.length()-1;
    while (r-l+1 >= 4) {
        if (s[l] == s[r]) {
            t += s[l];
            l += 1;
            r -= 1;
        } else if (s[l] == s[r-1]) {
            t += s[l];
            l += 1;
            r -= 2;
        } else if (s[l+1] == s[r]) {
            t += s[l+1];
            l += 2;
            r -= 1;
        } else if (s[l+1] == s[r-1]) {
            t += s[l+1];
            l += 2;
            r -= 2;
        } else {
            break;
        }
    }
    cout << t;
    if (l == r) {
        cout << s[l];
    } else if (l+1 == r) {
        cout << s[l];
        if (s[l] == s[l+1]) {
            cout << s[l];
        }
    } else if (l+2 == r) {
        if (s[l] == s[l+1]) {
            cout << s[l] << s[l];
            if (s[l] == s[l+2]) {
                cout << s[l];
            }
        } else if (s[l] == s[l+2]) {
            cout << s[l] << s[l];
        } else if (s[l+1] == s[l+2]) {
            cout << s[l+1] << s[l+1];
        } else {
            cout << s[l];
        }
    }
    reverse(t.begin(), t.end());
    cout << t;
}
