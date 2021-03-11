#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == 1) ans += 15;
        else if (i == 2) ans += 9;
        else if (i >= 3 && i <= 6) ans += 4;
        else ans += 5;
    }
    cout << ans;
}
