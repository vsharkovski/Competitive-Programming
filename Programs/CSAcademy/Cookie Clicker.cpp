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




int n, c, s;
vii fact;


void Solve() {
  cin >> n >> c >> s;
  vi ids(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    fact.push_back(ii(a, b));
    ids[i] = i;
  }

  int ans = 2e9;
  
  do {
  
    for (int mask = 0; mask < (1 << n); ++mask) {
      vi tobuy;
      for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
          tobuy.push_back(ids[i]);
        }
      }

  //    cout << "tobuy: ";
  //    for (int y : tobuy) cout << y << " ";
  //    cout << endl;

      int curr = 0, t = 0, persec = s;
      for (int i : tobuy) {
        if (curr < fact[i].first) {
          int x = (int)ceil(double(fact[i].first-curr) / double(persec));
          curr += x*persec;
          t += x;
        }
  //      cout << "bought (" << fact[i].first << "," << fact[i].second << ") at t=" << t << endl;
        curr -= fact[i].first;
        persec += fact[i].second;
      }
      if (curr < c) {
        int x = (int)ceil(double(c-curr) / double(persec));
        curr += x*persec;
        t += x;
      }
  //    cout << "t=" << t << endl << endl;
      if (t < ans) {
        ans = t;
      }
    }

  } while (next_permutation(all(ids)));
  
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


