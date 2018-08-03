#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;

// Works on all tests I can find except the judge one


void solve() {

  int n, q;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  cin >> q;
  while (q--) {
    int h, h1 = -1, h2 = -1;
    cin >> h;

    if (h < v[0]) {
      cout << "X " << v[0] << endl;
      continue;
    }
    if (h > v[n-1]) {
      cout << v[n-1] << " X" << endl;
      continue;
    }

    auto it = upper_bound(v.begin(), v.end(), h);
    if (it != v.end()) {
      h2 = *it;
    }

    it = prev( lower_bound(v.begin(), it, h) );
    if (*it < h) {
      h1 = *it;
    }

    if (h1 == -1) cout << "X"; else cout << h1;
    cout << ' ';
    if (h2 == -1) cout << "X"; else cout << h2;
    cout << endl;
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
