#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;


void main1() {

  int T;
  cin >> T;
  while (T--) {

    int n, p;
    cin >> n >> p;

    vector<int> v(p);
    for (int i = 0; i < p; ++i) {
      cin >> v[i];
    }

    bool found = 0;

    for (int mask = 0; mask < (1<<p); ++mask) {
      int m = 0;
      for (int j = 0; j < p; ++j) {
        if (mask & (1<<j)) {
          m += v[j];
        }
      }
      if (n == m) {
        found = 1;
        break;
      }
    }

    if (found) cout << "YES\n";
    else cout << "NO\n";

  }


}






int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  main1();
}
