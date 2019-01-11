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





int n, m;
ll ans;
vector<ll> a;
vector<int> vs, vf, vc, vr;
vector<int> indices;

inline bool drivable(int idx, ll vol) {
  ll v = vol, c = vc[idx];
  int s = vs[idx], f = vf[idx], r = vr[idx];
  for (int i = s; i < f; ++i) {
    ll d = (a[i+1] - a[i]) * c;
    if (d > v) {
      if (r == 0) {
        return false;
      }
      --r;
      v = vol;
    }
    if (d > v) {
      return false;
    }
    v -= d;
  }
  return true;
}

inline ll findvolume(int idx) {
  ll lo = ans, hi = (a[vf[idx]] - a[vs[idx]])*vc[idx], mid, res = hi;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (drivable(idx, mid)) {
      res = mid;
      hi = mid-1;
    } else {
      lo = mid+1;
    }
  }
  return res;
}

void Main() {
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vs.resize(m);
  vf.resize(m);
  vc.resize(m);
  vr.resize(m);
  ans = 0;
  for (int i = 0; i < m; ++i) {
    cin >> vs[i] >> vf[i] >> vc[i] >> vr[i];
    --vs[i], --vf[i];
    indices.push_back(i);
  }
  random_shuffle(indices.begin(), indices.end());
  for (int i : indices) {
    if (drivable(i, ans)) continue;
    ans = max(ans, findvolume(i));
  }
  cout << ans << '\n';
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
