#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;






void Main() {
    int n;
    cin >> n;
    vector<int> a(2*n+1);
    vector<vector<int>> pos(n+1);
    for (int i = 1; i <= 2*n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    pos[0].push_back(1);
    pos[0].push_back(1);
    ll ans = 0;
    for (int j = 0; j < 2; ++j) {
        for (int i = 1; i <= n; ++i) {
            ans += abs(pos[i][j] - pos[i-1][j]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
