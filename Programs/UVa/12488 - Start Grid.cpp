#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;




void _initialize();
int main() {
  _initialize();

  int n;
  while (cin >> n) {

    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }

    int cnt = 0;

    //Simulate the race
    int fj = 0;
    for (int i = 0; i < n; ++i) {
      fj = i;
      for (int j = i; j < n; ++j) {
        if (a[j] == b[i]) {
          fj = j;
          break;
        }
      }
      for (int j = fj; j > i; --j) {
        swap(a[j], a[j-1]);
        cnt++;
      }

    }

    cout << cnt << endl;
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
