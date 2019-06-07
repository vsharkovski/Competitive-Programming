#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int n, m;
map<int, pii> counts;
vector<int> A, B;
multiset<int> Bset;

bool possible(int limit) {
    multiset<int> s = Bset;
    for (int x : A) {
        // y <= x
        auto it = s.lower_bound(x - limit);
        if (it != s.end() && *it <= x) {
            s.erase(it);
        } else {
            // y > x
            it = s.lower_bound(x+1);
            if (it == s.end() || *it > x+limit) {
                return false;
            }
            s.erase(it);
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    A.resize(n);
    B.resize(m);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    if (n > m) {
        swap(n, m);
        swap(A, B);
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < m; ++i) {
        Bset.insert(B[i]);
    }

    int lo = 0, hi = 1e9, mid, ans = 1e9;
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
