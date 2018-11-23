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
  int n;
  cin >> n;

  vector<ll> a(n);
  multiset<ll> future;
  ll sum = 0;
  bool initok = 1;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
    future.insert(sum);
    if (sum < 0) initok = 0;
  }

  int ans = initok;
  ll fsum = sum;
  ll minsum = 1e17;
  sum = 0;

  for (int i = 1; i < n; ++i) {
    sum += a[i-1];
    minsum = min(sum, minsum);
    future.erase(future.find(sum));
    if (a[i] >= 0) {
      if (fsum - sum + minsum >= 0) {
        if (future.empty() || *future.begin() - sum >= 0) {
          ++ans;
        }
      }
    }
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
