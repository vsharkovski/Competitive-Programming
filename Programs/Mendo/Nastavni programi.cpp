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


const int mod = 750083;

int n, m;
string a, b;
int minlen[1002][1002];
int ways[1002][1002];

int F(int i, int j) {
  if (minlen[i][j] != -1) return minlen[i][j];
  minlen[i][j] = 1e9;
  if (i == n && j == m) {
    //done
    minlen[i][j] = 0;
    ways[i][j] = 1;
  } else if (i == n) {
    //only choice
    minlen[i][j] = 1 + F(i, j+1);
    ways[i][j] = ways[i][j+1];
  } else if (j == m) {
    //only choice
    minlen[i][j] = 1 + F(i+1, j);
    ways[i][j] = ways[i+1][j];
  } else { // i < n, j < m
    if (a[i] == b[j]) {
      //best choice
      minlen[i][j] = 1 + F(i+1, j+1);
      ways[i][j] = ways[i+1][j+1];
    } else {
      //first choice
      minlen[i][j] = 1 + F(i+1, j);
      ways[i][j] = ways[i+1][j];
      //second choice
      int attempt = 1 + F(i, j+1);
      if (attempt < minlen[i][j]) {
        //actual minimum length, so override previous choice
        minlen[i][j] = attempt;
        ways[i][j] = ways[i][j+1];
      } else if (attempt == minlen[i][j]) {
        //same length (minimum), so add to number of ways
        ways[i][j] += ways[i][j+1];
      }
    }
  }
  ways[i][j] %= mod;
  return minlen[i][j];
}

void _SOLVE_() {
  cin >> a >> b;
  n = a.length(), m = b.length();
  memset(minlen, -1, sizeof(minlen));
  F(0, 0);
  cout << ways[0][0] << endl;
//  cout << "ways: " << ways[0][0] << endl;
//  cout << "minlen: " << minlen[0][0] << endl;
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
