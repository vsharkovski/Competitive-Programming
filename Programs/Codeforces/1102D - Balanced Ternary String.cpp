#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
template <class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;






void Main() {
  int n;
  cin >> n;
  vi v(n);
  set<int> pos[3];
  int cnt[3] = {};
  for (int i = 0; i < n; ++i) {
    char ch;
    cin >> ch;
    v[i] = ch-'0';
    ++cnt[v[i]];
    pos[v[i]].insert(i);
  }
  int i = 0;
  while (cnt[0] < n/3) {
    if (v[i] != 0 && cnt[v[i]] > n/3) {
      --cnt[v[i]];
      ++cnt[0];
      pos[v[i]].erase(i);
      pos[0].insert(i);
      v[i] = 0;
    }
    ++i;
  }
  i = n-1;
  while (cnt[2] < n/3) {
    if (v[i] != 2 && cnt[v[i]] > n/3) {
      --cnt[v[i]];
      ++cnt[2];
      pos[v[i]].erase(i);
      pos[2].insert(i);
      v[i] = 2;
    }
    --i;
  }
  for (auto it = pos[2].begin(); it != pos[2].end(); ++it) {
    if (cnt[1] == n/3 || cnt[2] == n/3) break;
    v[*it] = 1;
    ++cnt[1];
    --cnt[2];
  }
  for (auto it = pos[0].rbegin(); it != pos[0].rend(); ++it) {
    if (cnt[0] == n/3 || cnt[1] == n/3) break;
    v[*it] = 1;
    ++cnt[1];
    --cnt[0];
  }
  for (int i = 0; i < n; ++i) {
    cout << v[i];
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
