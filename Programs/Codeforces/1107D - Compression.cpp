#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
template<class Key, class Compare = less<Key>>
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;






int n;
static int A[5201][5201];
static int tried[5201];
static int sumA[5201][5201];

bool possible(int x) {
  if (tried[x] != -1) {
    return tried[x];
  }
  for (int i = 1; i <= n; i += x) {
    for (int j = 1; j <= n; j += x) {
      int cnt = sumA[i+x-1][j+x-1] - sumA[i-1][j+x-1] - sumA[i+x-1][j-1] + sumA[i-1][j-1];
      if (cnt != 0 && cnt != x*x) {
        return false;
      }
    }
  }
  return tried[x] = 1;
}

void Main() {
  int charvalue[200];
  string hexistring = "0123456789ABCDEF";
  for (int i = 0; i < 16; ++i) {
    charvalue[hexistring[i]] = i;
  }
  cin >> n;
  memset(tried, -1, sizeof(tried));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; j += 4) {
      char ch;
      cin >> ch;
      int x = charvalue[ch];
      for (int k = 0; k < 4; ++k) {
        A[i][j+k] = (x >> (3-k)) & 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      sumA[i][j] = A[i][j] + sumA[i-1][j] + sumA[i][j-1] - sumA[i-1][j-1];
    }
  }
  int ans = 1;
  for (int x = n; x >= 1; --x) {
    if (n % x == 0) {
      if (possible(x)) {
        ans = x;
        break;
      }
    }
  }
  cout << ans << '\n';
//  for (int i = 1; i <= n; ++i) {
//    for (int j = 1; j <= n; ++j) {
//      cout << A[i][j];
//    }
//    cout << '\n';
//  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  #endif
  Main();
  return 0;
}
