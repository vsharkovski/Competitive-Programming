#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int maxn = 300005;

int n, m;
int a[maxn], b[maxn];

bool possible(int limit) {
    for (int i = 0; i <= n; ++i) {
        b[i] = a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (b[i-1] > b[i]) {
            if (b[i-1] - b[i] <= limit) {
                b[i] = b[i-1];
            } else {
                return false;
            }
        } else if (b[i-1] < b[i]) {
            int needed = m - (b[i] - b[i-1]);
            if (needed <= limit) {
                b[i] = b[i-1];
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int lo = 0, hi = m, mid, ans = hi;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (possible(mid)) {
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    cout << ans << '\n';

}
