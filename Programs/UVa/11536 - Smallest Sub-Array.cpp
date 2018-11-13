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
  vector<int> X(1000005);
  X[1] = 1;
  X[2] = 2;
  X[3] = 3;

  int T;
  cin >> T;
  for (int TC = 1; TC <= T; ++TC) {

    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 4; i <= N; ++i)
      X[i] = (X[i-1] + X[i-2] + X[i-3]) % M + 1;

    int ans = 1e9;
    int cnt[101] = {};
    int numhave = 0, j = 1;

    for (int i = 1; i <= N; ++i) {
      if (X[i] <= K) {
        ++cnt[X[i]];
        if (cnt[X[i]] == 1) ++numhave;
      }
      while (j < i && numhave == K && (X[j] > K || cnt[X[j]] > 1)) {
        if (X[j] <= K) --cnt[X[j]];
        ++j;
      }
      if (numhave == K) {
        ans = min(ans, i - j + 1);
      }
    }

    cout << "Case " << TC << ": ";
    if (ans == 1e9) cout << "sequence nai\n";
    else cout << ans << "\n";




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
