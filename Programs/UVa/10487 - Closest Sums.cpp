#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;




void _initialize();
int main() {
  _initialize();

  int n, caseNum = 1;
  while (cin >> n, n != 0) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    int m;
    cin >> m;
    cout << "Case " << caseNum << ":\n";
    while (m--) {
      int q;
      cin >> q;
      int best = -4e9;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i == j) continue;
          int w = v[i]+v[j];
          if (abs(q-w) < abs(q-best)) {
            best = w;
          }
        }
      }
      cout << "Closest sum to " << q << " is " << best << ".\n";
    }
    caseNum++;
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
