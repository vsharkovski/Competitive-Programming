#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;




int N, K, R;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
inline bool in(int r, int c) {
  return r >= 0 && r < R && c >= 0 && c < R;
}

int maxarea[300][11]; //maxarea[i][j] = max area for i-th room if plugging j leaks
int dp[300][3001]; //dp[i][k] = max possible to plug for rooms [0..i] having spent k money

int room[20][20];
vector<ii> leaks;
int numleaks;
int leakdata[10][20];

void Solve() {
  cin >> N >> K >> R;
  for (int i = 0; i < N; ++i) {
    leaks.clear();
    memset(leakdata, 0, sizeof(leakdata));
    //get room layout, get leaks positions
    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < R; ++c) {
        char ch;
        cin >> ch;
        if (ch == 'L') {
          room[r][c] = 10;
          leaks.emplace_back(r, c);
        } else {
          room[r][c] = ch - '0';
        }
      }
    }
    numleaks = leaks.size();
    //for each leak, find out which cells it would individually flood
    //store it as bitmask
    for (int j = 0; j < numleaks; ++j) {
      leakdata[j][leaks[j].first] |= (1 << (leaks[j].second));
      queue<ii> q;
      q.push(leaks[j]);
      while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        for (int d = 0; d < 4; ++d) {
          int r1 = r + dr[d], c1 = c + dc[d];
          if (in(r1, c1) && !(leakdata[j][r1] & (1 << c1))) {
            if (room[r1][c1] != 10 && room[r1][c1] <= room[r][c]) {
              leakdata[j][r1] |= (1 << c1);
              q.emplace(r1, c1);
            }
          }
        }
      }
    }
    //try all combinations of plugging leaks
    //j-th bit on = j-th leak is plugged
    for (int m = 0; m < (1 << numleaks); ++m) {
      int numoff = numleaks;
      int roomdata[20] = {};
      for (int j = 0; j < numleaks; ++j) {
        if (m & (1 << j)) {
          --numoff;
          for (int r = 0; r < R; ++r) {
            roomdata[r] |= leakdata[j][r];
          }
        }
      }
      int area = 0;
      for (int r = 0; r < R; ++r) {
        //add number of 0 bits (we consider up to (R-1)-th)
        area += __builtin_popcount(~roomdata[r] & ((1 << R)-1));
      }
      maxarea[i][numoff] = max(maxarea[i][numoff], area);
    }
  }
  //simple dynamic programming
  for (int k = 0; k <= K; ++k) {
    dp[0][k] = 0;
    for (int t = 0; t <= min(10, k); ++t) {
      if (k - t >= 0) {
        dp[0][k] = max(dp[0][k], maxarea[0][t]);
      }
    }
  }
  for (int i = 1; i < N; ++i) {
    for (int k = 0; k <= K; ++k) {
      dp[i][k] = 0;
      for (int t = 0; t <= min(10, k); ++t) {
        if (k - t >= 0) {
          dp[i][k] = max(dp[i][k], maxarea[i][t] + dp[i-1][k - t]);
        }
      }
    }
  }
  int res = 0;
  for (int k = 0; k <= K; ++k) {
    res = max(res, dp[N-1][k]);
  }
  cout << res << endl;
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
