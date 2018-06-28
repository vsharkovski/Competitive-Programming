#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;


void solve() {

  vector<ll> vals;

  ll trojce = 1;
  for (int j = 0; j < 21; ++j) {
    for (int i = 0; i < 33; ++i) {
      vals.push_back(trojce * (1LL<<i));
    }
    trojce = trojce * 3;
  }
  sort(vals.begin(), vals.end());

  int m;
  while (cin >> m, m != 0) {
    cout << *lower_bound(vals.begin(), vals.end(), m) << endl;
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
