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

  int n;
  cin >> n;
  vi a0(n), a1(n), d(n);
  for (int i = 0; i < n; ++i) {
    cin >> a0[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> a1[i];
  }
  for (int i = 0; i < n; ++i) {
    d[i] = a1[i] - a0[i];
  }
  
  int ans = 0;
   
//    for (int x : d) cout << setw(3) << x << " ";
//    cout << endl;
  
  for (int i = 0; i < n; ++i) {
    if (d[i] == 0) continue;
    if (d[i] > 0) {
      int minval = d[i], j;
      for (j = i+1; j < n && d[j] > 0; ++j) {
        minval = min(minval, d[j]);
      }
      ans += minval;
      for (int k = i; k < j; ++k) {
        d[k] -= minval;
      }
    } else { // d[i] < 0
      int maxval = d[i], j;
      for (j = i+1; j < n && d[j] < 0; ++j) {
        maxval = max(maxval, d[j]);
      }
      ans -= maxval; // -(-) = +
      for (int k = i; k < j; ++k) {
        d[k] -= maxval;
      }
    }
    i = -1;
//    for (int x : d) cout << setw(3) << x << " ";
//    cout << endl;
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








