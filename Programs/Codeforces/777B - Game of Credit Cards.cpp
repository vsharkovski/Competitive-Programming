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

  int cntb[10] = {}, cntc[10] = {};
  vi a(n);

  char ch;
  for (int i = 0; i < n; ++i) {
    cin >> ch;
    a[i] = ch - '0';
  }
  for (int i = 0; i < n; ++i) {
    cin >> ch;
    int d = ch - '0';
    ++cntb[d];
    ++cntc[d];
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int d;
    for (d = a[i]; d <= 9; ++d) {
      if (cntb[d] > 0) break;
    }
    if (d == 10) {
      d = 0;//d = i == 0;
      while (cntb[d] == 0) ++d;
      ans += 1;
    }
    --cntb[d];
//    cout << d;
  }
//  cout << endl;
  cout << ans << endl;

  ans = 0;
  for (int i = 0; i < n; ++i) {
    int d;
    for (d = a[i]+1; d <= 9; ++d) {
      if (cntc[d] > 0) break;
    }
    if (d == 10) {
      d = 0;//d = i == 0;
      while (cntc[d] == 0) ++d;
    } else {
      ans += 1;
    }
    --cntc[d];
//    cout << d;
  }
//  cout << endl;
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








