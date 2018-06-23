#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;



void program() {

  int T;
  cin >> T;
  while (T--) {

    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
      cin >> words[i];
    }

    int maxcnt = -1;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;

        int cnt = 0, leni = words[i].length(), lenj = words[j].length();
        // i nad j
        for (int k = -lenj+1; k < leni+lenj; ++k) { // b1
          int temp = 0;
          for (int l = 0; l < lenj; ++l) {
            if (k+l >= 0 && k+l < leni && words[j][l] == words[i][k+l]) {
              temp++;
            }
          }
          cnt = max(cnt, temp);
        }

        maxcnt = max(cnt, maxcnt);
      }
    }

    cout << maxcnt << endl;

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
