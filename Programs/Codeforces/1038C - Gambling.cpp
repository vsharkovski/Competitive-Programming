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
  vi a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  sort(all(a));
  sort(all(b));
  
  ll sa = 0, sb = 0;
  int i = n-1, j = n-1;
  bool plr = 1;
  while (i >= 0 || j >= 0) {
//    cout << "plr=" << plr << " "; if(i>=0)cout << "a[" << i << "]=" << a[i] << " "; if(j>=0)cout << "b[" << j << "]=" << b[j] << " "; cout << endl;
    if (plr) {
      if (j < 0 || (i >= 0 && a[i] > b[j])) {
        sa += a[i];
        --i;
      } else { //samo j
        --j;
      }
    } else {
      if (i < 0 || (j >= 0 && b[j] > a[i])) {
        sb += b[j];
        --j;
      } else {
        --i;
      }
    }
    plr = !plr;
  }

  cout << sa - sb << endl;

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







