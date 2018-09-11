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

  vi v(30000,-1);
  int n, p, t;
  cin >> n >> p >> t;
  
  vi moves = {0, 0, 0, 0, 1, -1, 1, 1, 1};
  int mi = 0, pos1 = 1;
  while (t--) {
    pos1 += moves[mi];
    mi = (mi + 1) % (moves.size());
  }
  
  v[pos1] = 1;
  for (int i = 2; i <= n; ++i) {
    v[pos1+i-1] = i;
  }
  
  cout << v[p] << endl;







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











