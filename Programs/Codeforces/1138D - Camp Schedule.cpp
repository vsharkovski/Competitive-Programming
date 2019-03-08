#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;





vector<int> getz(bitset<500005>& s, int n) {
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        z[i] = max(0, min(z[i - l], r - i + 1));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            l = i;
            r = i + z[i];
            ++z[i];
        }
    }
    return z;
}

void Main() {
    bitset<500005> s, t;
    int n, m;
    int n1 = 0, n0 = 0, nt1 = 0, nt0 = 0, nsv1 = 0, nsv0 = 0;

    string _str;
    cin >> _str;
    n = _str.length();
    for (int i = 0; i < n; ++i) {
        s[i] = _str[i] == '1';
        if (s[i]) ++n1; else ++n0;
    }
    cin >> _str;
    m = _str.length();
    for (int i = 0; i < m; ++i) {
        t[i] = _str[i] == '1';
        if (t[i]) ++nt1; else ++nt0;
    }
    _str.clear();

    if (m > n || nt1 > n1 || nt0 > n0) {
        for (int i = 0; i < n; ++i) {
            cout << s[i];
        }
        return;
    }
    if (nt0 == 0 || nt1 == 0) {
        for (int i = 0; i < n0; ++i) {
            cout << 0;
        }
        for (int i = 0; i < n1; ++i) {
            cout << 1;
        }
        return;
    }
    vector<int> z = getz(t, m);
    int idx = -1;
    for (int i = 1; i < m; ++i) {
        if (i + z[i] == m) {
            idx = i;
            for (int j = i; j < m; ++j) {
                if (t[j] == 0) {
                    ++nsv0;
                } else {
                    ++nsv1;
                }
            }
            break;
        }
    }
    int f1 = 1 + (n1 - nt1) / (nt1 - nsv1);
    int f0 = 1 + (n0 - nt0) / (nt0 - nsv0);
    int fcnt = min(f1, f0);
    if (idx == -1) {
        for (int i = 0; i < fcnt; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << t[j];
                if (t[j]) --n1; else --n0;
            }
        }
    } else {
        for (int i = 0; i < fcnt - 1; ++i) {
            for (int j = 0; j < idx; ++j) {
                cout << t[j];
                if (t[j]) --n1; else --n0;
            }
        }
        for (int j = 0; j < m; ++j) {
            cout << t[j];
            if (t[j]) --n1; else --n0;
        }
    }
    while (n0--) {
        cout << 0;
    }
    while (n1--) {
        cout << 1;
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
