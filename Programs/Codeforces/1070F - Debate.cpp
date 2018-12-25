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
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key (for multiset: pair(val, time of insertion))
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;






void _SOLVE_() {

    int n;
    cin >> n;

    int ans = 0, total = 0, na = 0, nb = 0;
    vector<int> a, b, none;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x == 0) {
            none.push_back(y);
        } else if (x == 1) {
            b.push_back(y);
        } else if (x == 10) {
            a.push_back(y);
        } else {
            total += 1;
            na += 1;
            nb += 1;
            ans += y;
//            cout << "ab: " << y << endl;
        }
    }

    sort(none.begin(), none.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    while (!a.empty() && !b.empty()) {
        total += 2;
        na += 1;
        nb += 1;
        ans += a.back() + b.back();
//        cout << "a: " << a.back() << ", b: " << b.back() << endl;
        a.pop_back();
        b.pop_back();
    }

    if (a.empty()) swap(a, b);

    while (!a.empty()) {
        if ((none.empty() || a.back() >= none.back()) && 2*nb >= total+1) {
            total += 1;
            na += 1;
            ans += a.back();
//            cout << "a: " << a.back() << endl;
            a.pop_back();
        } else if (!none.empty() && none.back() >= a.back() && 2*nb >= total+1 && 2*na >= total+1) {
            total += 1;
            ans += none.back();
//            cout << "none: " << none.back() << endl;
            none.pop_back();
        } else {
            break;
        }
    }

    while (!none.empty() && 2*na >= total+1 && 2*nb >= total+1) {
        total += 1;
        ans += none.back();
//        cout << "none: " << none.back() << endl;
        none.pop_back();
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
