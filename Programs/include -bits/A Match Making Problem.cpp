#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;


void solve() {

  int m, n;
  int TC = 1;
  while (cin >> m >> n, m != 0 && n != 0) {

    vector<int> a(m), b(n);
    for (int i = 0; i < m; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());

    cout << "Case " << TC << ": ";
    if (m > n) {
      cout << m-n << " " << a.back() << endl;
    } else {
      cout << 0 << endl;
    }




    TC++;
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
