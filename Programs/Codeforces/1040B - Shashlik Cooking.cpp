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





int n, k;
bitset<1010> b;

inline void flip(int i) {
  b.flip(i);
  for (int j = 1; j <= k; ++j) {
    if (i-j >= 0) b.flip(i-j);
    if (i+j < n) b.flip(i+j);
  }
}

void Solve() {
  cin >> n >> k;
  
  if (k >= n/2) {
    cout << 1 << endl << (n/2)+1 << endl;
    return;
  }
  
  vi ans(n+2000, 1);
  
  for (int i = 0; i <= k; ++i) {
    vi curr;
    b.reset();
    for (int j = i; j < n; j += k+k+1) {
      flip(j);
      curr.push_back(j);
    }
    bool ok = 1;
    for (int j = 0; j < n && ok; ++j) {
      if (b[j] != 1) ok = 0;
    }
//    cout << "i=" << i << endl << "b=" << b << endl;
    if (ok && curr.size() < ans.size()) ans = curr;
  }
  
  cout << ans.size() << endl;
  for (int x : ans) {
    cout << x+1 << " ";
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


