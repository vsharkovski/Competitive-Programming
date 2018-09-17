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
  
  int n, m, k;
  cin >> n >> m >> k;
  
  int a[2][5050] = {};
  int maxx[2] = {n/2, (n+1)/2};
  
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    if (x % 2 == 0) a[0][x/2] = 1;
    else a[1][(x+1)/2] = 1;
  }
  
  int ans = 0;
  
  for (int L = 0; L < 2; ++L) {
    for (int x = 1; x <= maxx[L]; ++x) {
//      cout << "L=" << L << " x=" << x << endl;
      if (a[L][x]) {
        x = x + m;
      } else {
        int y;
        bool bad = 0;
        for (y = x+1; !bad && y <= min(maxx[L], x+m); ++y) {
          if (a[L][y] == 1) bad = 1;
        }
        --y; ////////xxxxxxxxxxx
        if (bad) {
//          cout << "bad (y=" << y << ")\n";
          x = y + m;
        } else {
//          cout << "built at a[" << L << "][" << x << "]\n";
          ++ans;
          a[L][x] = 2;
          x = x + m;
        }
      }
    }
  }
  
//  for (int L = 0; L < 2; ++L) {
//    for (int x = 1; x <= maxx[L]; ++x) {
//      cout << a[L][x] << " ";
//    }
//    cout << endl;
//  }
  
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



