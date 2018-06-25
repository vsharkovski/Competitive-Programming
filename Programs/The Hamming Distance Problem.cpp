#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;



void main1() {

  int numDS;
  cin >> numDS;
  int Q = 0;
  for (int Q = 0; Q < numDS; ++Q) {

    int n, h;
    cin >> n >> h;

    for (int mask = 1; mask < (1<<n); ++mask) {
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        if (mask & (1<<j)) {
          cnt++;
        }
      }
      if (cnt == h) {
        for (int j = n-1; j >= 0; --j) {
          cout << ((mask & (1 << j)) > 0);
        }
        cout << endl;
      }
    }

    if (Q+1 < numDS) cout << endl;
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
