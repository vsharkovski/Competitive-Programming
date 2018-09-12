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







int ans = 0;

int n, q;
char ops[150][150];
string s;

void bf(int i) {
  if (i < n) {
    for (char ch = 'a'; ch <= 'f'; ++ch) {
      s[i] = ch;
      bf(i+1);
    }
    return;
  }
  string t = s;
  for (int j = 1; j <= n-1; ++j) {
    int k = t[j-1], l = t[j];
    if (ops[k][l] == 0) {
      t[n-1] = 0;
      break;
    }
    t[j] = ops[k][l];
    t[j-1] = '/';
  }
  if (t[n-1] == 'a') ++ans;
}

void Solve() {
  cin >> n >> q;
  for (char c1 = 'a'; c1 <= 'f'; ++c1) {
    for (char c2 = 'a'; c2 <= 'f'; ++c2) {
      ops[(int)c1][(int)c2] = 0;
    }
  }
  for (int i = 0; i < q; ++i) {
    char p1, p2, q1;
    cin >> p1 >> p2 >> q1;
    ops[(int)p1][(int)p2] = q1;
  }
  s.resize(n);
  bf(0);
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


















