#include <bits/stdc++.h>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;

const ll mod = 998244353;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}






void Solve() {

  int n, d, k;
  cin >> n >> d >> k;

  if (d >= n) { cout << "NO"; return; }

  vi degree(n, 0);
  priority_queue<ii> pq; // -distv, v ; distv = max dist. from any other vertex
  vii edges;

  for (int u = 0; u < d; ++u) {
    degree[u]++;
    degree[u+1]++;
    edges.push_back(ii(u, u+1));
    if (degree[u] < k) {
      pq.push(ii(-max(u, d-u), u));
    } else if (degree[u] > k) {
      cout << "NO"; return;
    }
  }

  for (int u = d+1; u < n; ++u) {
    if (pq.empty()) { cout << "NO"; return; }

    ii p = pq.top(); pq.pop();
    int dist = -p.first, v = p.second;

    if (dist >= d) { cout << "NO"; return; }

//    cout << "u=" << u+1 << " v=" << v+1 << " distv=" << dist << endl;

    degree[u]++;
    degree[v]++;
    edges.push_back(ii(u, v));
    if (degree[u] < k) pq.push(ii(-(dist+1), u));
    if (degree[v] < k) pq.push(ii(-dist, v));

  }

  cout << "YES\n";
  for (ii e : edges) {
    cout << e.first+1 << " " << e.second+1 << endl;
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








