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



const int OFS = 40001;

int N, F;
int T[42];
int dp[42][80002];
char vis[42][80002];
char result[42];

int dfs(int i, int s) {
  int& res = dp[i][OFS+s];
  if (res != -1) {
    return res;
  }
  if (i == N) {
    if (s == F) {
      return res = 1;
    } else {
      return res = 0;
    }
  }
  if (s == F) {
    return res = 0;
  }
  int res1 = dfs(i+1, s + T[i]);
  int res2 = dfs(i+1, s - T[i]);
  char& nxt = vis[i][OFS+s];
  if (res1 && res2) {
    nxt = '?';
    return res = 1;
  } else if (res1) {
    nxt = '+';
    return res = 1;
  } else if (res2) {
    nxt = '-';
    return res = 1;
  } else {
    return res = 0;
  }
}

void bfs() {
  queue<pi> q;
  q.emplace(0, 0);
  while (!q.empty()) {
    pi top = q.front(); q.pop();
    int i = top.first, s = top.second;
    char& sgn = vis[i][OFS+s];
    if (sgn == '/') continue; //already had this state in queue
    if (result[i] == '.') {
      result[i] = sgn;
    } else if (result[i] != '?' && sgn != result[i]) {
      result[i] = '?';
    }
    if (i + 1 < N) {
      if (sgn != '+') {
        q.emplace(i + 1, s - T[i]);
      }
      if (sgn != '-') {
        q.emplace(i + 1, s + T[i]);
      }
    }
    sgn = '/';
  }
}

void Solution() {
  while (cin >> N >> F, N != 0 || F != 0) {
    for (int i = 0; i < N; ++i) {
      cin >> T[i];
    }
    memset(dp, -1, sizeof(dp));
    int res = dfs(0, 0);
    if (res == 0) {
      cout << "*\n";
    } else {
      fill(result, result+N, '.');
      bfs();
      for (int i = 0; i < N; ++i) {
        cout << result[i];
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
