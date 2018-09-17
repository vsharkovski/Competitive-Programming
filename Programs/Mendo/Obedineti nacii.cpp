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
 
 
 
 
 
int n, I;
vector<vi> g;
 
int numCC = 0;
vector<vi> CCs;
 
vector<bool> visited;
void dfs1(int u) {
    visited[u] = 1;
    CCs[numCC].push_back(u);
    for (int v : g[u]) {
        if (visited[v] == 0) {
            dfs1(v);
        }
    }
}
 
void Solve() {
    cin >> n >> I;
    g.assign(n, vi());
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    visited.assign(n, 0);
    int totalsz = 0;
    for (int u = 0; u < n; ++u) {
        if (visited[u] == 0) {
            CCs.push_back(vi());
            dfs1(u);
            totalsz += CCs[numCC].size();
            ++numCC;
        }
    }
    ll cnt = 0;
    for (int i = 0; i < numCC; ++i) {
        cnt += CCs[i].size() * (totalsz - CCs[i].size());
//        cout << "CCi=" << i << " ; sz=" << CCs[i].size() << endl;
    }
    cnt /= 2;
    cout << cnt << endl;
 
 
 
 
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
