#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);

  int T;
  cin >> T;

  while (T--) {
    int D;
    cin >> D;

    string m[D];
    int l[D], h[D];
    for (int i = 0; i < D; ++i) {
      cin >> m[i] >> l[i] >> h[i];
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
      int P;
      cin >> P;
      int cnt = 0, namei = -1;

      //Just trusting the book on this one...
      for (int j = 0; j < D; ++j) {
        if (l[j] <= P && P <= h[j]) {
          cnt++;
          if (cnt >= 2) break;
          namei = j;
        }
      }

      if (cnt == 1) {
        cout << m[namei] << endl;
      } else {
        cout << "UNDETERMINED" << endl;
      }
    }

    if (T > 0) cout << endl; // I hate this.
  }

}
