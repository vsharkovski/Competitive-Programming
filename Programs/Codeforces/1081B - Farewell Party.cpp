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





void _SOLVE_() {

  int n;
  cin >> n;

  vi a(n+1), cnt(n+1, 0);
  ll suma = 0;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
    suma += a[i];
  }

  map<int, int> id;
  map<int, int> numdone;
  int nd = 0;
  vi b(n+1);

  for (int i = 0; i < n; ++i) {
    if (id.count(a[i]) == 0 || numdone[id[a[i]]] == n - a[i]) {
      id[a[i]] = ++nd;
      numdone[id[a[i]]] = 0;
    }
    ++numdone[id[a[i]]];
    b[i] = id[a[i]];
  }

  for (int i = 0; i < n; ++i) {
    if (numdone[id[a[i]]] != n - a[i]) {
      cout << "Impossible\n";
      return;
    }
  }

  cout << "Possible\n";
  for (int i = 0; i < n; ++i) {
    cout << b[i] << " ";
  }

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
