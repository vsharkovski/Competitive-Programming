#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key (for multiset: pair(val, time of insertion))
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;



int I, N, T;
vector<int> primes;
int dp[1024][16][128];
bool vis[1024][16][128];

int F(int n, int t, int i) {
  int& res = dp[n][t][i];
  if (res != -1) return res;
  if (n == N || t == T || i == I) {
    return res = (n == N) && (t == T);
  }
  bool& nxt = vis[n][t][i];
  if (n + primes[i] <= N && F(n + primes[i], t + 1, i + 1) == 1) {
    nxt = 1;
    return res = 1;
  } else if (F(n, t, i + 1) == 1) {
    nxt = 0;
    return res = 1;
  } else {
    return res = 0;
  }
}

void Solution() {
  primes.push_back(2);
  for (int x = 3; x < 300; ++x) {
    bool prime = true;
    for (int y = 2; y*y <= x; ++y) {
      if (x % y == 0) {
        prime = false;
        break;
      }
    }
    if (prime) {
      primes.push_back(x);
      primes.push_back(x);
    }
  }
  sort(primes.begin(), primes.end(), [&](int &x, int &y){
    string a = to_string(x), b = to_string(y);
    return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
  });
  I = primes.size();
  int Case = 1;
  while (cin >> N >> T, N != 0 || T != 0) {
    memset(dp, -1, sizeof(dp));
    int res = F(0, 0, 0);
    cout << "CASE " << Case++ << ":\n";
    if (res == 0) {
      cout << "No Solution.\n";
    } else {
      for (int n = 0, t = 0, i = 0;;) {
        if (n == N) {
          break;
        } else if (vis[n][t][i]) {
          if (n > 0) cout << '+';
          cout << primes[i];
          n += primes[i];
          ++t;
        }
        ++i;
      }
      cout << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  Solution();
}
