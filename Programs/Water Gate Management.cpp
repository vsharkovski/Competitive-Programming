#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;


void main1() {

  int n;
  cin >> n;
  int f[n], c[n];
  for (int i = 0; i < n; ++i) {
    cin >> f[i] >> c[i];
  }
  int m;
  cin >> m;
  for (int M = 1; M <= m; ++M) {
    int v, t;
    cin >> v >> t;
    ll finalc = 1e17;
    for (int mask = 1; mask < (1<<n); ++mask) {
      ll totalf = 0, totalc = 0;
      for (int j = 0; j < n; ++j) {
        if (mask & (1 << j)) {
          totalf += f[j];
          totalc += c[j];
        }
      }
      if (totalf * t >= v && totalc < finalc) {
        finalc = totalc;
      }
    }
    cout << "Case " << M << ": ";
    if (finalc == 1e17) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << finalc << endl;
    }
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
