#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template <class Key, class Compare = less<Key>>
using Tree = __gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;




int n, h;
static pi  segs[200005];
static int total[200005];
static int falling[200005];

void Main() {
  cin >> n >> h;
  for (int i = 0; i < n; ++i) {
    cin >> segs[i].first >> segs[i].second;
  }
  for (int i = 0; i < n; ++i) {
    total[i] = segs[i].second - segs[i].first;
    if (i > 0) {
      total[i] += total[i-1] + segs[i].first - segs[i-1].second;
    }
  }
  falling[0] = 0;
  for (int i = 1; i < n; ++i) {
    falling[i] = falling[i-1] + segs[i].first - segs[i-1].second;
  }
//  cout << "t: "; for (int i = 0; i < n; ++i){cout<<total[i]<<' ';};cout<<'\n';
//  cout << "f: "; for (int i = 0; i < n; ++i){cout << falling[i]<<' ';}cout<<'\n';
  int ans = h;
  for (int src = 0; src < n; ++src) {
    auto it = prev(lower_bound(falling, falling + n, h + falling[src]));
    int i = distance(falling, it);
    if (i < src) continue;
    int h1 = h - (falling[i] - falling[src]);
    int res = total[i] - (src == 0 ? 0 : total[src-1] + segs[src].first - segs[src-1].second) + h1;
    ans = max(ans, res);
//    cout << "src=" << src << " i=" << i << " h1=" << h1 << " res=" << res << '\n';
  }
  cout << ans << '\n';
}


int main() {
  ios::sync_with_stdio(false);
//  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
