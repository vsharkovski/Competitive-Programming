#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;




void program() {

  int m, q;
  cin >> m >> q;

  vector<string> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }

  while (q--) {

    string s;
    cin >> s;
    int len = s.length();
    int mindiff = 1e9, ansi = -1;

    for (int ti = 0; ti < m; ++ti) {
      int tlen = a[ti].length();
      if (tlen < len) continue;
      int diff = 1e9;
      for (int j = 0; j <= tlen-len; ++j) {
        int t = 0;
        for (int k = 0; k < len; ++k) {
          if (s[k] != a[ti][j+k]) {
            t++;
          }
        }
        diff = min(diff, t);
      }
      if (diff < mindiff) {
        mindiff = diff;
        ansi = ti;
      }
    }
    cout << ansi+1 << endl;

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
