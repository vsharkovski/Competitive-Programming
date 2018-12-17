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




void _SOLVE_() {
  stringstream ss;
  string line;
  int TC;
  cin >> TC;
  while (TC--) {

    int P, T;
    cin >> P >> T;

    vector<set<int>> opinion(P);

    getline(cin, line);
    while (getline(cin, line), line != "") {
      ss << line;
      int i, j;
      ss >> i >> j;
      --i, --j;
      opinion[i].insert(j);
      ss.clear();
    }

    int numcc = P;
    for (int i = 0; i < P; ++i) {
      for (int j = i-1; j >= 0; --j) {
        if (opinion[i] == opinion[j]) {
          --numcc;
          break;
        }
      }
    }

    cout << numcc << endl;
    if (TC > 0) cout << endl;
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


/**

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



class dsu {
public:
  vector<int> p, rank;
  dsu(int n) {
    rank.assign(n, 0);
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return (p[x] == x) ? x : (p[x] = get(p[x]));
  }
  inline bool unite(int x, int y) {
    x = get(x), y = get(y);
    if (x != y) {
      if (rank[x] > rank[y]) p[y] = x; else p[x] = y;
      if (rank[x] == rank[y]) ++rank[y];
      return true;
    }
    return false;
  }
};

void _SOLVE_() {
  stringstream ss;
  string line;
  int TC;
  cin >> TC;
  while (TC--) {

    int P, T;
    cin >> P >> T;

    dsu d(P);
    vector<set<int>> opinion(P);

    getline(cin, line);
    while (getline(cin, line), line != "") {
      ss << line;
      int i, j;
      ss >> i >> j;
      --i, --j;
      opinion[i].insert(j);
      ss.clear();
    }

    int numcc = P;
    for (int i = 0; i < P; ++i) {
      for (int j = i-1; j >= 0; --j) {
        if (d.get(i) != d.get(j) && opinion[i] == opinion[j]) {
          d.unite(i, j);
          --numcc;
          break;
        }
      }
    }

//    for (int i = 0; i < P; ++i) {
//      cout << "id(" << i+1 << ") = " << d.get(i) << " ; ";
//      cout << "opinion[" << i+1 << "]:";
//      for (int x : opinion[i]) cout << " " << x;
//      cout << "\n";
//    }

    cout << numcc << endl;
    if (TC > 0) cout << endl;
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

**/
