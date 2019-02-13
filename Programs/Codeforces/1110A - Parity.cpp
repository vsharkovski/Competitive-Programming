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
    int b, k;
    cin >> b >> k;
    int a[100005];
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    int rem = 0;
    int bb = 1;
    for (int i = k-1; i >= 0; --i) {
        rem += a[i] * bb;
        rem %= 2;
        bb *= b;
        bb %= 2;
    }

    cout << (rem ? "odd" : "even") << '\n';
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
