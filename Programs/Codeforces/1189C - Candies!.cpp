#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
 
 
const int maxn = 100010;
 
 
int n;
int s[maxn];
 
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        if (i > 0) s[i] += s[i-1];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int res = s[r];
        if (l > 0) res -= s[l-1];
        cout << res/10 << '\n';
    }
}
