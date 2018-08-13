#include <bits/stdc++.h>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;

const ll mod = 998244353;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}







void Solve() {
  int n;
  ll p, q, r;
  cin >> n >> p >> q >> r;

  vector<ll> a(n), maxprev(n), minprev(n), maxnext(n), minnext(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  maxprev[0] = a[0];
  minprev[0] = a[0];
  for (int i = 1; i < n; ++i) {
    maxprev[i] = max(maxprev[i-1], a[i]);
    minprev[i] = min(minprev[i-1], a[i]);
  }
  maxnext[n-1] = a[n-1];
  minnext[n-1] = a[n-1];
  for (int i = n-2; i >= 0; --i) {
    maxnext[i] = max(maxnext[i+1], a[i]);
    minnext[i] = min(minnext[i+1], a[i]);
  }

//  cout << "\na:       "; for (int i = 0; i < n; ++i) cout << setw(12) << right << a[i] << " ";
//  cout << "\nmaxprev: "; for (int i = 0; i < n; ++i) cout << setw(12) << right << maxprev[i] << " ";
//  cout << "\nminprev: "; for (int i = 0; i < n; ++i) cout << setw(12) << right << minprev[i] << " ";
//  cout << "\nmaxnext: "; for (int i = 0; i < n; ++i) cout << setw(12) << right << maxnext[i] << " ";
//  cout << "\nminnext: "; for (int i = 0; i < n; ++i) cout << setw(12) << right << minnext[i] << " ";
//  cout << "\n";

  ll ans = -9e18;

  for (int i = 0; i < n; ++i) {
    ll x = p < 0 ? minprev[i] * p : maxprev[i] * p;
    ll y = q * a[i];
    ll z = r < 0 ? minnext[i] * r : maxnext[i] * r;
    ans = max(ans, x + y + z);
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








