#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




void Main() {

    int n;
    cin >> n;
    char grid[505][505];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i < n-1; ++i) {
        for (int j = 1; j < n-1; ++j) {
            set<char> s;
            s.insert(grid[i-1][j-1]);
            s.insert(grid[i+1][j+1]);
            s.insert(grid[i-1][j+1]);
            s.insert(grid[i+1][j-1]);
            if (s.size() == 1 && grid[i][j] == 'X' && grid[i-1][j-1] == 'X') {
                ++ans;
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
