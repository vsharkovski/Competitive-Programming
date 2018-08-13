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





struct Item {
  int t, d, p, i;
  bool operator < (Item &rhs) {
    return d < rhs.d;
  }
};

int n;
vector<Item> items;
int maxd; //after this no items remain

int dp[102][2010]; //item id, time when considered
bool taken[102][2010];

int najdi(int i, int t) {
  if (i == n || t >= maxd) return 0;
  if (dp[i][t] != -1) return dp[i][t];

  dp[i][t] = najdi(i+1, t); //ne zemaj
  taken[i][t] = 0;
  if (t + items[i].t < items[i].d) { //ima vreme da se zeme
    int kandidat = items[i].p + najdi(i+1, t + items[i].t); //zemaj
    if (kandidat > dp[i][t]) { //poveke se isplati da se zeme
      dp[i][t] = kandidat;
      taken[i][t] = 1;
    }
  }

  return dp[i][t];
}

void Solve() {
  cin >> n;
  maxd = 0;
  for (int i = 0; i < n; ++i) {
    Item pr;
    pr.i = i+1;
    cin >> pr.t >> pr.d >> pr.p;
    items.push_back(pr);
    maxd = max(maxd, pr.d);
  }

  sort(all(items)); //sortiraj spored d

  memset(dp, -1, sizeof(dp));
  cout << najdi(0, 0) << endl;

  vi indices;
  int i = 0, t = 0;
  while (i < n && t < maxd) {
    bool took = taken[i][t];
    if (took) {
      indices.push_back(items[i].i);
      t += items[i].t;
    }
    ++i;
  }

  cout << indices.size() << endl;
  for (int i : indices) cout << i << " ";


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








