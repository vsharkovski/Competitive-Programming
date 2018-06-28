#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;


void solve() {

  string s;
  cin >> s;
  vector<vector<int>> v(130);
  for (int i = 0; i < s.length(); ++i) {
    v[s[i]].push_back(i);
  }

  auto it = v[0].begin();

  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;

    int minpos = -1, maxpos = -1;
    int pos = -1;

    int i;
    for (i = 0; i < t.length(); ++i) {
      char ch = t[i];
      vector<int>& vv = v[ch];
      it = upper_bound(vv.begin(), vv.end(), pos);
      if (it == vv.end()) break;
      pos = vv[distance(vv.begin(), it)];
      if (minpos == -1) minpos = pos;
      maxpos = pos;
    }

    if (i == t.length()) {
      cout << "Matched " << minpos << " " << maxpos << endl;
    } else {
      cout << "Not matched\n";
    }


  }

}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  solve();
}
