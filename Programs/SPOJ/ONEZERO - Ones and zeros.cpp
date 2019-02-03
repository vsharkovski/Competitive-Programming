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




struct State {
    int rem;
    string num;
    State(int r, string n) : rem(r), num(n) {}
    State() {}
};

void Main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int n;
        cin >> n;
        int visited[20005] = {};
        queue<State> q;
        visited[1] = 1;
        q.emplace(1, "1");
        while (!q.empty()) {
            State top = q.front();
            q.pop();
            if (top.rem == 0) {
                cout << top.num << '\n';
                break;
            }
            for (int d = 0; d < 2; ++d) {
                int rem1 = (10*top.rem + d) % n;
                if (visited[rem1] == 0) {
                    visited[rem1] = 1;
                    q.emplace(rem1, top.num + char(d + '0'));
                }
            }
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
