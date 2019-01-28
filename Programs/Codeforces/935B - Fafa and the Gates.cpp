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
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        bool gate = x == y && x != 0;
        if (s[i] == 'R') {
            ++x;
        } else {
            ++y;
        }
//        cout << "x=" << x << " y=" << y << " chr=" << s[i] << "\n";
        if (gate && i >= 2 && s[i] == s[i-1]) {
            ++ans;
        }
    }
    cout << ans << '\n';
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
