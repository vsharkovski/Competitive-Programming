#include <bits/stdc++.h>
#define endl '\n'
using namespace std;



void _initialize();
int main() {
  _initialize();

  int k;
  while (cin >> k) {
    vector<pair<int,int>> v;
    for (int y = k+1; y <= 2*k; ++y) {
      if ((k*y)%(y-k) == 0) {
        v.emplace_back((k*y)/(y-k), y);
      }
    }
    cout << v.size() << endl;
    for (auto p : v) {
      cout << "1/" << k << " = 1/" << p.first << " + 1/" << p.second << endl;
    }
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
