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
  int n, k;
  cin >> n >> k;

  int cnt[102] = {};
  int maxi = 0;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
    maxi = max(maxi, cnt[x]);
  }

  while (maxi % k != 0) ++maxi;
  int ans = 0;

  for (int x = 1; x <= 100; ++x) {
    if (cnt[x] > 0)
    ans += max(0, maxi - cnt[x]);
  }

  cout << ans << endl;




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
