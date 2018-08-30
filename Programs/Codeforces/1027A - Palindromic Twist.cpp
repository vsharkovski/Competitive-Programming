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
 
 
 
 
int n;
string s;

vector<char> options[200];

bool najdi(int i, int j) {
  if (i < 0 || j >= n) return 1;
  for (char c1 : options[s[i]]) {
    for (char c2 : options[s[j]]) {
      if (c1 == c2 && najdi(i-1, j+1)) return 1;
    }
  }
  return 0;
}
 
void Solve() {
  options['a'].push_back('b');
  options['z'].push_back('y');
  for (char ch = 'b'; ch <= 'y'; ++ch) {
    options[ch].push_back(ch-1);
    options[ch].push_back(ch+1);
  }
  
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> s;  
    bool ans = najdi(n/2-1, n/2);
    if (ans) cout << "YES\n"; else cout << "NO\n";
  
  
  
  
  
  
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
