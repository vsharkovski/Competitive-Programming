#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



const int maxn = 300005;

int n, m;
int a[maxn];

bool possible(int limit) {
    int pr = 0, cr;
    for (int i = 0; i < n; ++i) {
        cr = a[i];
        if (pr > cr) {
            if (pr - cr <= limit) {
                cr = pr;
            } else {
                return false;
            }
        } else if (pr < cr) {
            int needed = m - (cr - pr);
            if (needed <= limit) {
                cr = pr;
            }
        }
        pr = cr;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
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
