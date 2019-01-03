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




typedef pair<char, int> pci;

int N;
char M[51][51];
string dp[51][51];

string dfs(int i, int j) {
  string& res = dp[i][j];
  if (res != "?") {
    return res;
  }
  if (i == j) {
    return res = "";
  }
  // i to j
  res = M[i][j];
  // i < k1 < k2 < j
  for (int k1 = i+1; k1 < j; ++k1) {
    char ch1 = M[i][k1];
    if (ch1 == '*') continue;
    for (int k2 = k1; k2 < j; ++k2) {
      char ch2 = M[j][k2];
      if (ch2 == ch1) {
        string att = ch1 + dfs(k1, k2) + ch2;
        if (att.length() > res.length() ||
           (att.length() == res.length() && lexicographical_compare(att.begin(), att.end(), res.begin(), res.end()))) {
          res = att;
        }
      }
    }
  }
  return res;
}

void Solution() {
  int T;
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cin >> M[i][j];
        dp[i][j] = "?";
      }
    }
    string res = dfs(0, N - 1);
    if (res == "") {
      cout << "NO PALINDROMIC PATH\n";
    } else {
      cout << res << '\n';
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
