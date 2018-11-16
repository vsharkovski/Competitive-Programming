#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;





void Solve() {
  int n, m;

  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  cin >> m;
  vi b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());

  int mindiff = 1e9;
  int bestw = -1;

  for (int i = n-1; i >= 0; --i) {
    auto it = lower_bound(b.begin(), b.end(), a[i]);
    if (it != b.end()) {
      int diff = *it - a[i];
      if (diff < mindiff) {
        mindiff = diff;
        bestw = a[i];
      }
    }
  }

  cout << bestw << endl;
}



int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  Solve();
}
