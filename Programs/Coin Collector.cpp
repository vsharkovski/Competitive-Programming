#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;



void solve() {

  int T;
  cin >> T;
  while (T--) {

    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
      cin >> c[i];
    }

    int s = c[0], m = 2; //always can get first and last
    for (int i = 1; i < n-1; ++i) {
      if (s + c[i] < c[i+1]) {
        //can get i-th coin
        s += c[i];
        ++m;
      }
    }

    cout << m << endl;

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
