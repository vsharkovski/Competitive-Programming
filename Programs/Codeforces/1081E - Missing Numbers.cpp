#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




void Main() {

    int n;
    ll a[100005];

    cin >> n;
    for (int i = 2; i <= n; i += 2) {
        cin >> a[i];
    }
    a[0] = 0;

    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 1) {
            a[i] = -1;
            for (ll x = sqrt(sum)+1; x <= 205000; ++x) {
                ll xsq = x*x;
                ll ysq = xsq + a[i+1];
                ll y = sqrt(ysq);
                if (y * y == ysq) {
                    a[i] = xsq - sum;
                    break;
                }
            }
            if (a[i] == -1) {
                cout << "No\n";
                return;
            }
        }
        sum += a[i];
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << ' ';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef _DEBUG
//        freopen("in.txt", "r", stdin);
//        freopen("out.txt", "w", stdout);
    #endif
    Main();
    return 0;
}
