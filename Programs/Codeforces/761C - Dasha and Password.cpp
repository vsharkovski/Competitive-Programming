#include <bits/stdc++.h>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;

const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}






void Solve() {
  int n, m;
  cin >> n >> m;
  
  int a[52][52];
  int closest[52][3];
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char ch;
      cin >> ch;
      if ('0' <= ch && ch <= '9') {
        a[i][j] = 0;
      } else if ('a' <= ch && ch <= 'z') {
        a[i][j] = 1;
      } else {
        a[i][j] = 2;
      }
    }
    closest[i][0] = closest[i][1] = closest[i][2] = 1e8;
    for (int j = 0; j < m; ++j) {
      int x = a[i][j];
      closest[i][x] = min(closest[i][x], j);
    }
    for (int j = m-1, k = 1; j > 0; --j, ++k) {
      int x = a[i][j];
      closest[i][x] = min(closest[i][x], k);
    }
 }
  
  int ans = 2e9;
  
  int basecnt[3] = {};
  for (int i = 0; i < n; ++i) basecnt[a[i][0]]++;
  if (basecnt[0] > 0 && basecnt[1] > 0 && basecnt[2] > 0) {
    cout << 0 << endl;
    return;
  }
  
  //             i, j, k
  int jobs[3] = {0, 1, 2};

  do {
    for (int i = 0; i < n-2; ++i) {
      for (int j = i+1; j < n-1; ++j) {
        for (int k = j+1; k < n; ++k) {
          int cand = closest[i][jobs[0]] + closest[j][jobs[1]] + closest[k][jobs[2]];
          ans = min(ans, cand);
        }
      }
    }
  } while (next_permutation(jobs, jobs+3));
  
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


















