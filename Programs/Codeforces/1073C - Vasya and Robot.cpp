#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int getd[200];

int n, x, y;
string s;

void update(pi& p, int i, int sgn) {
    p.first += dx[getd[s[i]]] * sgn;
    p.second += dy[getd[s[i]]] * sgn;
}

bool possible(pi p, int m) {
    int d = abs(p.first - x) + abs(p.second - y);
    return d % 2 == m % 2 && m >= d;
}

bool ok(int len) {
    pi pos(0, 0);
    for (int i = len; i < n; ++i) {
        update(pos, i, 1);
    }
    if (possible(pos, len)) return true;
    for (int r = len; r < n; ++r) {
        update(pos, r-len, 1);
        update(pos, r, -1);
        if (possible(pos, len)) return true;
    }
    return false;
}

void _SOLVE_() {
    getd['U'] = 0; getd['D'] = 2; getd['R'] = 1; getd['L'] = 3;
    cin >> n >> s >> x >> y;
    if (possible(pi(0, 0), n) == 0) {
        cout << -1 << endl;
        return;
    }
    int lo = 0, hi = n, mid, ans = n;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (ok(mid)) {
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  _SOLVE_();
}
