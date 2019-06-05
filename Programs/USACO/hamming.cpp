#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
LANG: C++
TASK: hamming
*/

int main() {
    #ifndef _DEBUG
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0);

    int n, b, d;
    cin >> n >> b >> d;

    vector<int> v;

    for (int m = 0; m < (1 << b); ++m) {
        bool ok = true;
        for (int x : v) {
            if (__builtin_popcount(x ^ m) < d) {
                ok = false;
                break;
            }
        }
        if (ok) {
            v.push_back(m);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << v[i];
        if (i+1 == n || i % 10 == 9) {
            cout << '\n';
        } else {
            cout << ' ';
        }
    }

}
