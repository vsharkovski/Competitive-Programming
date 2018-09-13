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

  int k;
  cin >> k;
  
  vii g(k+1, ii(-1, -1));
  
  for (int i = 0; i < k-1; ++i) {
    int u, v;
    cin >> u >> v;
    if (g[u].first == -1) {
      g[u].first = v;
    } else {
      g[u].second = v;
    }
    if (g[v].first == -1) {
      g[v].first = u;
    } else {
      g[v].second = u;
    }
  }
  vi seq1, seq2;
  int u = 0, prev = -1, nxt;
  while (u != -1) {
    seq1.push_back(u);
    nxt = g[u].first == prev ? g[u].second : g[u].first;
    prev = u;
    u = nxt;
  }
  u = k, prev = -1;
  while (u != -1) {
    seq2.push_back(u);
    nxt = g[u].first == prev ? g[u].second : g[u].first;
    prev = u;
    u = nxt;
  }
  for (int x : seq1) {
    cout << x << " ";
  }
  for (int j = seq2.size()-1; j >= 0; --j) {
    cout << seq2[j] << " ";
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








