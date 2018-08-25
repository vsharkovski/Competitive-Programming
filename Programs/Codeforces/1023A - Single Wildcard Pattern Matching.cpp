#include <bits/stdc++.h>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;

const int mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}




void Solve() {

  int n, m;
  cin >> n >> m;

  string s, t;
  cin >> s >> t;
  
  if (s.find("*") == string::npos) {
    if (s == t) cout << "YES";
    else cout << "NO";
    return;
  }
  
  deque<char> a, b;
  for (int i = 0; i < n; ++i) {
    a.push_back(s[i]);
  }
  for (int i = 0; i < m; ++i) {
    b.push_back(t[i]);
  }
  
  while (!a.empty() && !b.empty() && a.back() == b.back()) {
    a.pop_back();
    b.pop_back();
  }
  while (!a.empty() && !b.empty() && a.front() == b.front()) {
    a.pop_front();
    b.pop_front();
  }
  
  if (a.empty() || (a.size() == 1 && a.front() == '*')) {
    cout << "YES";
  } else {
    cout << "NO";
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






