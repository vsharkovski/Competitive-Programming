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
  string s;
  cin >> s;
  int len = s.length();
  for (int i = 1; i < len; ++i) {
    if (s[i] == s[i-1]) {
      char sol = 'a';
      if (i+1 == len) {
        while (sol == s[i-1]) ++sol;
      } else {
        while (sol == s[i-1] || sol == s[i+1]) ++sol;
      }
      s[i] = sol;
    }
  }
  cout << s << endl;
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




