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

  string a, b;
  cin >> a >> b;
  
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) continue;
    if (i+1 < n && a[i+1] == b[i] && a[i] == b[i+1]) {
      swap(a[i], a[i+1]);
//      cout << "swapping a[" << i << "]=" << a[i] << " and a[" << i+1 << "]=" << a[i+1] << endl;
      ++ans;
    } else {
      a[i] = b[i];
//      cout << "set a[" << i << "] to " << b[i] << endl;
      ++ans;
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




