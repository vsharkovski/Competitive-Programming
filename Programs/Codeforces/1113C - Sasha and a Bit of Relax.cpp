#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;



void Main() {
    int n;
    cin >> n;
    map<int, int> cnt[2];
    ll ans = 0;
    int p = 0;
    ++cnt[1][p];
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        p ^= a;
        ans += cnt[i % 2][p];
        ++cnt[i % 2][p];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
