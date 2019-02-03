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
    int K;
    cin >> K;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int dist[100005];
    fill(dist, dist+K+1, 1e9);
    dist[1] = 0;
    pq.emplace(0, 1);
    while (!pq.empty()) {
        pi top = pq.top();
        pq.pop();
        int d = top.first, u = top.second;
        if (d > dist[u]) continue;
        for (pi edg : {pi((10*u) % K, 0), pi((u+1) % K, 1)}) {
            int v = edg.first, w = edg.second;
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    cout << 1 + dist[0] << '\n';
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
