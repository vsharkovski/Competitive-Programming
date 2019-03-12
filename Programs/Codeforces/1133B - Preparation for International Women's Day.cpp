#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;







void Main() {
    int n, k;
    cin >> n >> k;
    int cnt[105] = {};
    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        d %= k;
        ++cnt[d];
    }
    int ans = 0;
    for (int d = 0; d < k; ++d) {
        if (cnt[d] > 0 && cnt[(k - d) % k] > 0) {
            if (d == (k-d) % k) {
                int m = cnt[d] / 2;
                cnt[d] -= 2*m;
                ans += 2*m;
            } else {
                int m = min(cnt[d], cnt[(k - d) % k]);
                cnt[d] -= m;
                cnt[(k - d) % k] -= m;
                ans += 2*m;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
