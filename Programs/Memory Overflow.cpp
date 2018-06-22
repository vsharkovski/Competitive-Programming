#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;




void _initialize();
int main() {
  _initialize();

  int t;
  cin >> t;
  for (int T = 0; T < t; ++T) {

    int n, k;
    cin >> n >> k;

    int a[300];
    for (int i = 0; i < 300; ++i) a[i] = -10000;

    int cnt = 0;

    for (int i = 0; i < n; ++i) {
      char ch;
      cin >> ch;
      if (a[ch] + k >= i) {
        cnt++;
      }
      a[ch] = i;
    }

    cout << "Case " << T+1 << ": " << cnt << endl;

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
