#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
 
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template <class Key, class Compare = less<Key>>
//using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;
 
const int MAXN = 300005;
 
int N;
static int want[MAXN];
static int parent[MAXN];
vector<int> children[MAXN];
static int depth[MAXN];
static int answer[MAXN];
set<pi> data[MAXN];
set<pi>* pointer[MAXN];
 
void add(set<pi>* d, pi x, int dpth) {
    auto it = d->insert(x).first;
    if (it != d->begin() && prev(it)->second >= x.second) {
        // x can be ignored since prev.first < x.first (the id)
        // so a node with bigger 'want' will already be processed before x
        // so remove x
        answer[x.first] = depth[x.first] - dpth - 1;
        d->erase(it);
        return;
    }
    ++it;
    while (it != d->end() && it->second <= x.second) {
        // same argument as above
        answer[it->first] = depth[it->first] - dpth - 1;
        auto nxt = next(it);
        d->erase(it);
        it = nxt;
    }
}
 
void dfs(int u, int dpth) {
    depth[u] = dpth;
    for (int v : children[u]) {
        dfs(v, dpth+1);
        // merge data from children
        if (pointer[v]->size() > pointer[u]->size()) {
            swap(pointer[v], pointer[u]);
        }
        while (pointer[v]->size() > 0) {
            auto beg = pointer[v]->begin();
            add(pointer[u], *beg, depth[u]);
            pointer[v]->erase(beg);
        }
    }
    // add current to data
    add(pointer[u], pi(u, want[u]), depth[u]);
//    cout << "u=" << u << ": ";
//    for (auto& zz : *pointer[u]) {
//        cout << zz.first << ' ' << zz.second << " ; ";
//    }
//    cout << endl;
}
 
void Main() {
    cin >> N >> want[0];
    ++N;
    for (int i = 1; i < N; ++i) {
        cin >> want[i] >> parent[i];
        children[parent[i]].push_back(i);
    }
    for (int i = 0; i < N; ++i) {
        pointer[i] = &data[i];
    }
    dfs(0, 0);
    // clear the data from 0 (the source)
    while (pointer[0]->size() > 0) {
        auto beg = pointer[0]->begin();
        answer[beg->first] = depth[beg->first] - depth[0];
        pointer[0]->erase(beg);
    }
    for (int i = 1; i < N; ++i) {
        cout << answer[i] << '\n';
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
