#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key (for multiset: pair(val, time of insertion))
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;





int n;
int id[100];
int bad[100];
vector<char> nodes;
vector<int> visited;
string order;
bool found;

void dfs(int u, int numon, int msk) {
  visited[u] = 1;
  order[2 * (numon - 1)] = nodes[u];
  if (numon == n) {
    found = 1;
    cout << order << '\n';
  } else {
    for (int v = 0; v < n; ++v) {
      if (v != u && visited[v] == 0 && (bad[v] & msk) == 0) {
        dfs(v, numon + 1, msk | (1 << v));
      }
    }
  }
  visited[u] = 0;
}

void Main() {
  int T;
  string line, str;
  cin >> T;
  getline(cin, line);
  while (T--) {
    n = 0;
    nodes.clear();
    stringstream ss;
    getline(cin, line);
    getline(cin, line);
//    cout << "! " << line << '\n';
    ss << line;
    while (ss >> str) {
      nodes.push_back(str[0]);
      ++n;
    }
    sort(nodes.begin(), nodes.end());
    for (int i = 0; i < n; ++i) {
      id[nodes[i]] = i;
      bad[i] = 0;
    }
    getline(cin, line);
    ss.clear();
//    cout << "! " << line << '\n';
    ss << line;
    while (ss >> str) {
      int u = id[str[0]];
      int v = id[str[2]];
      bad[u] |= (1 << v);
    }
    visited.assign(n, 0);
    found = 0;
    order.resize(2*n - 1);
    for (int i = 0; i < 2*n - 1; ++i) {
      order[i] = ' ';
    }
    for (int i = 0; i < n; ++i) {
      dfs(i, 1, 1 << i);
    }
    if (found == 0) {
      cout << "NO\n";
    }
    if (T > 0) {
      cout << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  Main();
}
