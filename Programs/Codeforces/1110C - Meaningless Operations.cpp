#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;



void Main() {
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a;
        if ((a & (a + 1)) == 0) {
            bool done = 0;
            for (int x = 2; x*x <= a; ++x) {
                if (a % x == 0) {
                    cout << a/x << '\n';
                    done = 1;
                    break;
                }
            }
            if (!done) {
                cout << 1 << '\n';
            }
        } else {
            int x = 0;
            while (a > 0) {
                a >>= 1;
                ++x;
            }
            cout << (1 << x) - 1 << '\n';
        }
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
