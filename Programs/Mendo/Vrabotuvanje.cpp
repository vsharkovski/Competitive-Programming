#include <bits/stdc++.h>
using namespace std;




int N, M, K;
int cena[201];
int predava[201]; // bitmask

int dp[201][3][3][3][3][3][3][3][3];

#define brzo(c, i, j) min(2, c + int((predava[i] >> j) & 1))

int f(int i, int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8) {
  if (i == K) {
    if (c1 != 2) return 1e9;
    if (N == 1) return 0;
    if (c2 != 2) return 1e9;
    if (N == 2) return 0;
    if (c3 != 2) return 1e9;
    if (N == 3) return 0;
    if (c4 != 2) return 1e9;
    if (N == 4) return 0;
    if (c5 != 2) return 1e9;
    if (N == 5) return 0;
    if (c6 != 2) return 1e9;
    if (N == 6) return 0;
    if (c7 != 2) return 1e9;
    if (N == 7) return 0;
    if (c8 != 2) return 1e9;
    if (N == 8) return 0;
    return 1e9;
  }
  int& ref = dp[i][c1][c2][c3][c4][c5][c6][c7][c8];
  return ref = ref != -1 ? ref : min(
    f(i+1, c1, c2, c3, c4, c5, c6, c7, c8),
    cena[i] + f(i+1, brzo(c1,i,1), brzo(c2,i,2), brzo(c3,i,3), brzo(c4,i,4), brzo(c5,i,5), brzo(c6,i,6), brzo(c7,i,7), brzo(c8,i,8))
  );
}

int main() {
  cin >> N >> M;
  
  int ans = 0;
  int b[10] = {};
  
  while (M--) {
    int p, t;
    cin >> p >> t;
    ans += p;
    while (t--) {
      int s;
      cin >> s;
      b[s] = min(b[s]+1, 2);
    }
  }

  cin >> K;
  for (int i = 0; i < K; ++i) {
    int p, t;
    cin >> p >> t;
    cena[i] = p;
    predava[i] = 0;
    while (t--) {
      int s;
      cin >> s;
      predava[i] |= (1 << s);
    }
  }

  memset(dp, -1, sizeof(dp));
  ans += f(0, b[1], b[2], b[3], b[4], b[5], b[6], b[7], b[8]);

  cout << ans << endl;
  
}
