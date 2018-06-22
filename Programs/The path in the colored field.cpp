#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;




void _initialize();
int main() {
  _initialize();

  int m;
  while (cin >> m) {

    vector<pair<int, int>> ones, threes;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        char ch;
        cin >> ch;
        if (ch == '1') {
          ones.emplace_back(i, j);
        } else if (ch == '3') {
          threes.emplace_back(i, j);
        }
      }
    }
    int ans = -100;
    for (auto po : ones) {
      int i = po.first, j = po.second;
      int mindist = 1e9;
      for (auto pt : threes) {
        int k = pt.first, l = pt.second;
        mindist = min(mindist, abs(i-k) + abs(j-l));
      }
      ans = max(ans, mindist);
    }
    cout << ans << endl;

  }


}




void _initialize() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
}
