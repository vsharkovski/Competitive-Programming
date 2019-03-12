#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;







void Main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0 && b[i] == 0) {
            ++ans;
        }
    }
    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0) {
            if (a[i] < 0) {
                b[i] = -b[i];
                a[i] = -a[i];
            }
            int g = __gcd(a[i], b[i]);
            a[i] /= g;
            b[i] /= g;
            ++cnt[pair<int, int>(-b[i], a[i])];
        }
    }
    int maxcnt = 0;
    for (auto& kvp : cnt) {
        maxcnt = max(maxcnt, kvp.second);
    }
    ans += maxcnt;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
