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
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




int S, N, S1, S2;
ll stix[32];
vector<ll> data[32];
ll ans = 0;

void _SOLVE_() {
  cin >> S >> N;
  for (int i = 0; i < S; ++i) {
    cin >> stix[i];
  }
  sort(stix, stix+S);
  S1 = S/2;
  S2 = S - S1;
  for (int m = 0; m < (1 << S1); ++m) {
    int numtaken = 0;
    ll len = 0;
    ll maxs = 0;
    for (int i = 0; i < S1; ++i) {
      if (m & (1 << i)) {
        ++numtaken;
        len += stix[i];
        maxs = max(maxs, stix[i]);
      }
    }
    data[numtaken].push_back(len);
    if (numtaken == N && len-maxs > maxs) {
      ++ans;
    }
  }
  for (int i = 0; i <= N; ++i) {
    sort(data[i].begin(), data[i].end());
  }
  for (int m = 1; m < (1 << S2); ++m) {
    int numtaken = 0;
    ll len = 0;
    ll maxs = 0;
    for (int i = 0; i < S2; ++i) {
      if (m & (1 << i)) {
        ++numtaken;
        len += stix[S1+i];
        maxs = max(maxs, stix[S1+i]);
      }
    }
    if (numtaken > N) continue;
    auto it = upper_bound(data[N-numtaken].begin(), data[N-numtaken].end(), -(len-2*maxs));
//    cout << "len=" << len << " numtaken=" << numtaken << " maxs=" << maxs << "\n";
//    cout << "data[" << N-numtaken << "]={";
//    for (ll x : data[N-numtaken]) cout << x << " ";
//    cout << "}\n";
    ll dist = distance(it, data[N-numtaken].end());
    ans += dist;
  }
  cout << ans << endl;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  _SOLVE_();
}
