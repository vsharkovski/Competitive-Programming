#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;




void program() {

  int T;
  cin >> T;
  for (int _T = 0; _T < T; ++_T) {

    int r, c;
    cin >> r >> c;
    bool a[r+2][c+2];
    memset(a, 1, sizeof(a));
    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
        char ch;
        cin >> ch;
        a[i][j] = ch-'0';
      }
    }
    int minstp = 1e9;
    for (int j = 1; j <= c; ++j) {
      int steps = 0;
      for (int i = 1; i <= r; ++i) {
        if (a[i][j] == 1) {

          int min0dst = 1e9;
          for (int k = 1; k <= c; ++k) {
            if (a[i][k] == 0) {
              min0dst = min(min0dst, abs(j-k));
            }
          }

          if (min0dst == 1e9) {
            steps = 1e9;
            break;
          } else {
            steps += min0dst;
          }

        }
      }
      minstp = min(minstp, steps);
    }
    if (minstp == 1e9) minstp = -1;
    cout << "Case " << _T+1 << ": " << minstp << endl;

  }



}






int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  program();
}
