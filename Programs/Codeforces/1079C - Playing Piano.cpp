#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;




int n;
vi a;
vi dp[5];
vi nxt[5];

int F(int i, int p) {
  if (i == n) return 1;
  if (dp[p][i] != -1) return dp[p][i];
  int res = 0, nx = 0;
  if (a[i] > a[i-1]) {
    for (int c = p + 1; c < 5 && res == 0; ++c) {
      res = F(i+1, c);
      nx = c;
    }
  } else if (a[i] < a[i-1]) {
    for (int c = p - 1; c >= 0 && res == 0; --c) {
      res = F(i+1, c);
      nx = c;
    }
  } else {
    for (int c = 0; c < 5 && res == 0; ++c) {
      if (c != p) {
        res = F(i+1, c);
        nx = c;
      }
    }
  }
  nxt[p][i] = nx;
  return dp[p][i] = res;
}

void Solve() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int b = 0; b < 5; ++b) {
    dp[b].assign(n, -1);
    nxt[b].assign(n, -1);
  }
  for (int b0 = 0; b0 < 5; ++b0) {
    if (F(1, b0)) {
      int c = b0;
      cout << c+1 << " ";
      for (int i = 1; i < n; ++i) {
        c = nxt[c][i];
        cout << c+1 << " ";
      }
      return;
    }
  }
  cout << "-1\n";
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
