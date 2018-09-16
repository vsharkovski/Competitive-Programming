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
 




vector<ll> a;

void bf(int p, int cnt, ll curr) {
  if (p == 18) {
    a.push_back(curr);
    return;
  }
  bf(p+1, cnt, 10*curr);
  if (cnt < 3) {
    for (int d = 1; d <= 9; ++d) {
      bf(p+1, cnt+1, 10*curr + d);
    }
  }
}

void Solve() {
  
  bf(0, 0, 0);
  a.push_back(1e18);
  
  int T;
  cin >> T;
  while (T--) {
    ll L, R;
    cin >> L >> R;
    cout << distance(lower_bound(all(a), L), upper_bound(all(a), R)) << endl;
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


