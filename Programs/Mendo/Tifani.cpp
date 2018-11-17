#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;





int quick[4] = {0b001, 0b010, 0b100, 0};
inline int popcount(int x) {
  return ((x >> 2) & 1) + ((x >> 1) & 1) + (x & 1);
}

void Solve() {

  int N;
  cin >> N;

  int a[100005];
  for (int i = 0; i < N; ++i) {
    char ch;
    cin >> ch;
    if (ch == 'R') a[i] = 0;
    else if (ch == 'Y') a[i] = 1;
    else a[i] = 2;
  }

  int dp[2][4][4][4][4];
  int curr = 0, nxt = 1;

  for (int l1 = 3; l1 >= 0; --l1)
    for (int l2 = 3; l2 >= 0; --l2)
      for (int r1 = 3; r1 >= 0; --r1)
        for (int r2 = 3; r2 >= 0; --r2)
          dp[nxt][l1][l2][r1][r2] = 0;

  for (int i = N-1; i >= 0; --i, swap(nxt, curr))
    for (int l1 = 3; l1 >= 0; --l1)
      for (int l2 = 3; l2 >= 0; --l2)
        for (int r1 = 3; r1 >= 0; --r1)
          for (int r2 = 3; r2 >= 0; --r2)
            dp[curr][l1][l2][r1][r2] = max(
              popcount(quick[a[i]] | quick[l1] | quick[l2]) + dp[nxt][a[i]][l1][r1][r2],
              popcount(quick[a[i]] | quick[r1] | quick[r2]) + dp[nxt][l1][l2][a[i]][r1]
            );

  cout << dp[nxt][3][3][3][3] << "\n";
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
