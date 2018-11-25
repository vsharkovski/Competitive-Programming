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
  cin >> n >> m;

  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  ll cnt = 0;
  int hneed = 1;

  for (int i = 0; i < n; ++i) {
    if (a[i] >= hneed) {
      cnt += a[i] - 1;
      hneed += 1;
    } else {
      cnt += a[i] - 1;
    }
  }
  if (hneed <= a.back()) {
    cnt -= a.back() - hneed + 1;
  }

  cout << cnt << endl;



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
