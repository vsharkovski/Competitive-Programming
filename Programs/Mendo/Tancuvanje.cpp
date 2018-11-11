#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
const double EPS = 1e-9;
const ll mod = 1e9 + 7;




int T[100005];
int G[100005];
bool gone[100005];
int prv[100005];
int nxt[100005];

struct Comp {
  bool operator () (const ii &l, const ii &r) const {
    int d1 = abs(T[l.first] - T[l.second]);
    int d2 = abs(T[r.first] - T[r.second]);
    return !(d1 != d2 ? d1 < d2 : l.second < r.first);
  }
};

void Solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> T[i];
  for (int i = 0; i < n; ++i)
    cin >> G[i];

  priority_queue<ii, vector<ii>, Comp> pq;
  vector<ii> ans;

  gone[0] = 0;
  prv[0] = nxt[n-1] = -1;
  for (int i = 1; i < n; ++i) {
    gone[i] = 0;
    nxt[i-1] = i;
    prv[i] = i-1;
    if (G[i] != G[i-1]) {
      pq.emplace(i-1, i);
    }
  }

  while (!pq.empty()) {
    ii top = pq.top(); pq.pop();
    int u = top.first, v = top.second;
    if (gone[u] || gone[v]) continue;
//    cout << "going u=" << u+1 << " v=" << v+1 << " dT=" << abs(T[u]-T[v]) << "\n";
    ans.emplace_back(u, v);
    gone[u] = gone[v] = 1;
    if (prv[u] != -1) {
      nxt[prv[u]] = nxt[v];
    }
    if (nxt[v] != -1) {
      prv[nxt[v]] = prv[u];
    }
    if (prv[u] != -1 && nxt[v] != -1 && G[prv[u]] != G[nxt[v]]) {
      pq.emplace(prv[u], nxt[v]);
    }
  }

  cout << ans.size() << endl;
  for (ii &p : ans) {
    cout << p.first+1 << " " << p.second+1 << endl;
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
