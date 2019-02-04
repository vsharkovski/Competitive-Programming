#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




int n, m;
vector<int> G[100005];

void Main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> seq;
    vector<int> inpq(n+1, 0);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    inpq[1] = 1;
    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        seq.push_back(top);
        for (int v : G[top]) {
            if (inpq[v] == 0) {
                inpq[v] = 1;
                pq.push(v);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << seq[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
