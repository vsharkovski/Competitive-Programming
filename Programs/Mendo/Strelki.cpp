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





int n;
vector<int> nxt;
vector<int> available;
vector<int> ciklus;
vector<int> p;

int get(int x) {
  if (p[x] == x) {
    return x;
  } else {
    return p[x] = get(p[x]);
  }
}

void unite(int x) {
  int y = get(nxt[x]);
  if (y == x) {
    ciklus[x] = 1;
    p[y] = x;
  } else {
    p[x] = y;
  }
}


void _SOLVE_() {
  cin >> n;
  nxt.resize(n+1);
  available.assign(n+1, 1);
  ciklus.assign(n+1, 0);
  p.resize(n+1);
  p[0] = 0;
  for (int i = 1; i <= n; ++i) {
    p[i] = i;
    int j;
    cin >> j;
    nxt[i] = j;
  }
  int Q;
  cin >> Q;
  vector<pi> queries(Q);
  for (int Qi = 0; Qi < Q; ++Qi) {
    int qtype, idx;
    cin >> qtype >> idx;
    queries[Qi] = {qtype, idx};
    if (qtype == 2) {
      available[idx] = 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (available[i] && nxt[i] != 0) {
      unite(i);
    }
  }
  vector<int> answers(Q);
  for (int Qi = Q-1; Qi >= 0; --Qi) {
    int qtype = queries[Qi].first, idx = queries[Qi].second;
    if (qtype == 1) {
      int y = get(idx);
      if (ciklus[y]) {
        answers[Qi] = -2;
      } else {
        answers[Qi] = y;
      }
    } else {
      unite(idx);
    }
  }
  for (int Qi = 0; Qi < Q; ++Qi) {
    if (queries[Qi].first == 1) {
//      cout << "ending from " << queries[Qi].second << ": ";
      if (answers[Qi] == -2) {
        cout << "CIKLUS\n";
      } else {
        cout << answers[Qi] << "\n";
      }
    } else {
//      cout << "removing at " << queries[Qi].second << "\n";
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
  _SOLVE_();
}
