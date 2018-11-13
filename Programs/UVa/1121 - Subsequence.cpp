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
  int N, S;
  while (cin >> N >> S) {

    vi a(N);
    for (int i = 0; i < N; ++i) {
      cin >> a[i];
    }

    int ans = N+1;
    int len = 0, sum = 0;

    for (int i = 0; i < N; ++i) {
      sum += a[i];
      ++len;
      while (sum - a[i-len+1] >= S) {
        sum -= a[i-len+1];
        --len;
      }
      if (sum >= S) {
        ans = min(ans, len);
      }
    }
    if (ans == N+1) ans = 0;

    cout << ans << endl;




  }




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
