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
  int N;
  cin >> N;

  vi a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  int ans = 0;

  for (int i = N-1; i >= 1; --i) {
    int x = a[i];
    int cx = N - i;
    for (int j = i-1; j >= 0; --j) {
      int y = a[j];
      int cy = N - j;
      ans = max(ans, x*cx + y*cy - y*cx);
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
