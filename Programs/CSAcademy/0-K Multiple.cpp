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
    int N, K;
    cin >> N >> K;
    vector<int> digits = {0, K};
    vector<int> visited(N+5, 0);
    queue<pair<int, string>> q;
    q.emplace(0, "");
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        if (top.first == 0 && top.second.size() > 0) {
            cout << top.second << '\n';
            return;
        }
        for (int d : digits) {
            if (top.first == 0 && d == 0) continue;
            int f1 = (10*top.first + d) % N;
            if (visited[f1] == 0) {
                visited[f1] = 1;
                q.emplace(f1, top.second + char(d + '0'));
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
