#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;


void solve() {

  int n;
  while (cin >> n) {

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());

    int m;
    cin >> m;

    int bestdelta = 2e9, besti = -1, bestj = -1;

    for (auto it = v.begin(); it != v.end(); ++it) {
      int p1 = *it;
      auto jt = prev(upper_bound(it, v.end(), m-p1));
      if (jt == v.end() || *jt > (m-p1)) {
        --jt;
      }
      int p2 = *jt;
      int m1 = p1 + p2;

      if (m1 != m) continue;

      int i = distance(v.begin(), it);
      int j = distance(v.begin(), jt);
      if (i == j) continue;

      int delta = abs(j-i);
      if (delta < bestdelta) {
        bestdelta = delta;
        besti = i;
        bestj = j;
      }
    }

    int a = v[besti], b = v[bestj];
    if (a > b) swap(a, b);
    cout << "Peter should buy books whose prices are " << a << " and " << b << ".\n\n";

  }



}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  solve();
}
