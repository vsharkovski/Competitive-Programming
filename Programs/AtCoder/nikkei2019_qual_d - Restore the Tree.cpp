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
 
 
 
 
const int unvisited = 0, explored = 1, visited = 2;
 
int N, M;
vector<int> G[100005];
 
int parent[100005];
int numparents[100005];
int status[100005];
 
void dfs(int u) {
  status[u] = explored;
  for (int v : G[u]) {
    if (parent[v] == -1 || status[parent[v]] == explored) {
      parent[v] = u;
    }
    if (status[v] == unvisited) {
      dfs(v);
    }
  }
  status[u] = visited;
}
 
 
void Main() {
  cin >> N >> M;
  memset(numparents, 0, sizeof(numparents));
  for (int i = 0; i < N-1+M; ++i) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    ++numparents[b];
  }
  int root;
  for (int u = 1; u <= N; ++u) {
    if (numparents[u] == 0) {
      root = u;
      break;
    }
  }
  memset(status, unvisited, sizeof(status));
  memset(parent, -1, sizeof(parent));
  dfs(root);
  parent[root] = 0;
  for (int u = 1; u <= N; ++u) {
    cout << parent[u] << '\n';
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
