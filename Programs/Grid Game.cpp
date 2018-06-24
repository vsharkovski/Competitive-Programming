#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;


void main1() {

  int T;
  cin >> T;
  while (T--) {


    int n;
    cin >> n;

    int a[8][8];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
      }
    }

    int corder[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int ans = 1e9;

    do {
      bool donei[8] = {};
      int t = 0;
      for (int i = 0; i < n; ++i) {
        t += a[i][corder[i]];
      }
      ans = min(ans, t);
    } while (next_permutation(corder, corder+n)); //you've gotta start thinking with PERMUTATIONS

    cout << ans << endl;

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
