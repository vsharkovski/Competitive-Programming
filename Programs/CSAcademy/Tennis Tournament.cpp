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
  int n, k, m;
  cin >> n >> k >> m;
  
  vi v((1<<n)+1, -1);

  if ((k == 1 && m != 0) || (k == (1<<n) && m != n) || (m == n && k != (1<<n)) || (m > 0 && k < (1<<m))) { cout << -1; return; }
  
  if (m == 0) {
    v[1] = k;
    v[2] = 1<<n;
    for (int i = 3, j = 1; i <= (1<<n); ++i, ++j) {
      if (j == k) ++j;
      v[i] = j;
    }
  } else if (m == n) {
    for (int i = 1; i <= (1<<n); ++i) {
      v[i] = i;
    }
  } else {
    for (int i = 1; i < (1<<m); ++i) {
      v[i] = i;
    }
    v[1<<m] = k;
    v[(1<<m) + 1] = 1<<n;
    for (int i = (1<<m)+2, j = 1<<m; i <= (1<<n); ++i, ++j) {
      if (j == k) ++j;
      v[i] = j;
    }
  }
  
//  cout << "n=" << n << " k=" << k << " m=" << m << endl;
  for (int i = 1; i <= (1<<n); ++i) {
    cout << v[i] << ' ';
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


















