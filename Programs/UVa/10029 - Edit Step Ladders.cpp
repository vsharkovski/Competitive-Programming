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




int N;
vector<string> words;
map<string, int> dp;


int dfs(string s) {
  if (binary_search(words.begin(), words.end(), s) == 0) {
    return -1e9;
  }
  if (dp.count(s)) {
    return dp[s];
  }
  int n = s.length();
  int res = 0;
  // change letter
  for (int i = 0; i < n; ++i) {
    string s1 = s;
    for (char ch = s[i] + 1; ch <= 'z'; ++ch) {
      s1[i] = ch;
//      cout << "s=" << s << " {change} s1=" << s1 << '\n';
      res = max(res, 1 + dfs(s1));
    }
  }
  // add letter
  for (int i = 0; i <= n; ++i) {
    string s1 = s;
    s1.insert(i, "a");
    for (char ch = i < n ? s[i] : 'a'; ch <= 'z'; ++ch) {
      s1[i] = ch;
      if (lexicographical_compare(s.begin(), s.end(), s1.begin(), s1.end())) {
//        cout << "s=" << s << " {add} s1=" << s1 << '\n';
        res = max(res, 1 + dfs(s1));
      }
    }
  }
  // remove letter
  if (n > 1) {
    for (int i = 0; i < n; ++i) {
      string s1 = s;
      s1.erase(s1.begin() + i);
      if (lexicographical_compare(s.begin(), s.end(), s1.begin(), s1.end())) {
//        cout << "s=" << s << " {remove} s1=" << s1 << '\n';
        res = max(res, 1 + dfs(s1));
      }
    }
  }
  return dp[s] = res;
}

void Solution() {
  string word;
  while (cin >> word) {
    words.push_back(word);
  }
  N = words.size();
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ans = max(ans, 1 + dfs(words[i]));
  }
  cout << ans << '\n';
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
