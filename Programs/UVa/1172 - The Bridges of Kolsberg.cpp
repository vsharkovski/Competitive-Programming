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





int N1, N2;
int os1[1005];
int os2[1005];
int value1[1005];
int value2[1005];
pi dp[1005][1005];

inline bool betterchoice(pi& res, pi& opt) {
  return opt.first > res.first || (opt.first == res.first && opt.second < res.second);
}

pi F(int i1, int i2) {
  if (dp[i1][i2].first != -1) return dp[i1][i2];
  pi res = {0, 0}, opt;
  if (i1 < N1 && i2 < N2) {
    opt = F(i1+1, i2);
    if (betterchoice(res, opt)) {
      res = opt;
    }
    opt = F(i1, i2+1);
    if (betterchoice(res, opt)) {
      res = opt;
    }
    if (os1[i1] == os2[i2]) {
      opt = F(i1+1, i2+1);
      opt.first += value1[i1] + value2[i2];
      opt.second += 1;
      if (betterchoice(res, opt)) {
        res = opt;
      }
    }
  }
  return dp[i1][i2] = res;
}

map<string, int> id[2]; //1=cityname, 2=ostype
int idsz[2];

int getid(int i, string& s) {
  return id[i].count(s) ? id[i][s] : (id[i][s] = idsz[i]++);
}

void _SOLVE_() {
  int T;
  cin >> T;
  while (T--) {
    for (int i = 0; i < 2; ++i) {
      id[i].clear(),
      idsz[i] = 0;
    }
    cin >> N1;
    for (int i = 0; i < N1; ++i) {
      string name, os;
      int val;
      cin >> name >> os >> val;
      getid(0, name);
      os1[i] = getid(1, os);
      value1[i] = val;
    }
    cin >> N2;
    for (int i = 0; i < N2; ++i) {
      string name, os;
      int val;
      cin >> name >> os >> val;
      getid(0, name);
      os2[i] = getid(1, os);
      value2[i] = val;
    }
    for (int i1 = 0; i1 <= N1; ++i1)
      for (int i2 = 0; i2 <= N2; ++i2)
        dp[i1][i2] = {-1, -1};
    pi ans = F(0, 0);
    cout << ans.first << " " << ans.second << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  _SOLVE_();
}
