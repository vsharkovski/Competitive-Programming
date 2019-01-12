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
 
 
 
 
 
 
void Solution() {
  ll n;
  ll a[200005];
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] -= i + 1;
  }
  sort(a, a+n);
  ll b1 = a[n/2], b2 = b1, ans1 = 0, ans2 = 0, ans3 = 0;
  if (n % 2 == 1) {
    b2 = a[n/2+1];
  }
  for (int i = 0;i < n; ++i) {
    ans1 += abs(a[i] - b1);
    ans2 += abs(a[i] - b2);
    ans3 += abs(a[i] - 0);
  }
  ll ans = min({ans1, ans2, ans3});
  cout << ans;
}
 
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Solution();
}
