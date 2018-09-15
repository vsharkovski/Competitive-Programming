#include <bits/stdc++.h>
 
#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
 
const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}
 






void Solve() {

  int n;
  cin >> n;
  
  vi w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  int d;
  cin >> d;
  
  bool ogr[10][10]; // ogr[a][b] = a nad b
  memset(ogr, 0, sizeof(ogr));
  for (int i = 0; i < d; ++i) {
    int a, b;
    cin >> a >> b;
    ogr[a-1][b-1] = 1;
  }
  
  
  vi ids(n);
  for (int i = 0; i < n; ++i) {
    ids[i] = i;
  }
  
  vi best = ids;
  int ans = 1e9;
  
  do {
    int work = 0;
    for (int i = 0; i < n; ++i) {
      work += i*w[ids[i]];
      for (int j = i+1; j < n; ++j) {
        if (ogr[ids[i]][ids[j]]) {
          i = n, j = n, work = 1e9;
        }
      }
    }
    if (work < ans) {
      ans = work;
      for (int i = 0; i < n; ++i) {
        best[i] = ids[i];
      }
    }
  } while (next_permutation(all(ids)));

  for (int i = 0; i < n; ++i) {
    cout << best[i] + 1 << " ";
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








