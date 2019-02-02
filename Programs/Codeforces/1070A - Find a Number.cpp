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
    int rem, sum;
    string num;
    State(int x, int y, string z) : rem(x), sum(y), num(z) {}
    State() {}
};

void Main() {
    int D, S;
    static int visited[505][5015] = {};
    queue<State> q;
    cin >> D >> S;
    visited[0][0] = 1;
    q.emplace(0, 0, "");
    while (!q.empty()) {
        State top = q.front();
        q.pop();
//        cout << "rem=" << top.rem << " sum=" << top.sum << " num=" << top.num << '\n';
        if (top.sum > S) continue;
        if (top.sum == S && top.rem == 0) {
            cout << top.num << '\n';
            return;
        }
        for (int x = 0; x <= 9; ++x) {
            int rem1 = (10*top.rem + x) % D;
            int sum1 = top.sum + x;
            if (visited[rem1][sum1] == 0) {
                visited[rem1][sum1] = 1;
                q.emplace(rem1, sum1, top.num + char(x + '0'));
            }
        }
    }
    cout << -1 << '\n';
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
