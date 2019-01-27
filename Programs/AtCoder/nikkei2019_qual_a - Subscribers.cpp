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
 
  int n, a, b;
  cin >> n >> a >> b;
  int maxi = -1, mini = n+1;
  for (int i = 0; i <= min(a, b); ++i) {
    int u = a + b - i;
    if (u >= min(a, b) && u <= n) {
      maxi = max(maxi, i);
      mini = min(mini, i);
    }
  }
  cout << maxi << ' ' << mini << '\n';
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
