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




vector<string> citations;
vector<string> bibitems;
map<string, string> bibitemline;

bool baraj(string& line, string& pref, vector<string>& v) {
  auto pos = line.find(pref);
  bool foundone = 0;
  while (pos != string::npos) {
    foundone = 1;
    string name = "";
    int i = pos + pref.size();
    while (i < line.size() && line[i] != '}') {
      name += line[i];
      ++i;
    }
    if (i < line.size() && line[i] == '}') {
      v.push_back(name);
      pos = line.find(pref, pos+1);
    } else {
      break;
    }
  }
  return foundone;
}

void _SOLVE_() {
  string citpref = "\\cite{";
  string bibpref = "\\bibitem{";
  string line;
  while (getline(cin, line)) {
    if (baraj(line, citpref, citations)) {

    } else if (baraj(line, bibpref, bibitems)) {
      bibitemline[bibitems.back()] = line;
    }
  }
  bool correct = 1;
  for (int i = 0; i < citations.size(); ++i) {
    if (citations[i] != bibitems[i]) {
      correct = 0;
      break;
    }
  }
  if (correct) {
    cout << "Correct\n";
  } else {
    cout << "Incorrect\n";
    cout << "\\begin{thebibliography}{99}\n";
    for (int i = 0; i < citations.size(); ++i) {
      cout << bibitemline[citations[i]] << "\n";
    }
    cout << "\\end{thebibliography}\n";
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
