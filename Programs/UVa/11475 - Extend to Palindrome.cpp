#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
template <class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




// The idea is to find the longest palindrome at the end of the initial string
// You can use Z-algorithm or KMP to do this
// I used Z-algorithm, uncomment the lines below to see the idea

vector<int> makez(string& s) {
  int n = s.length();
  vector<int> z(n);
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    z[i] = max(0, min(z[i - l], r - i + 1));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      l = i;
      r = i + z[i];
      ++z[i];
    }
  }
  return z;
}

void Main() {
  int n, m;
  string s, t;
  vector<int> z;
  while (cin >> s) {
    n = s.length();
    t = s;
    reverse(t.begin(), t.end());
    t = t + "#" + s;
    m = 2*n + 1;
    z = makez(t);
//    cout << "t: " << t << '\n';
//    cout << "z: "; for (int i = 0; i < m; ++i) {cout << z[i];} cout << '\n';
    int i;
    for (i = n+1; i < m; ++i) {
      if (z[i] == m - i) {
        break;
      }
    }
    cout << s;
    for (i = i-1; i > n; --i) {
      cout << t[i];
    }
    cout << '\n';
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  Main();
}
