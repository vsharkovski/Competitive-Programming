#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;




void _initialize();
int main() {
  _initialize();

  int T;
  cin >> T;
  while (T--) {

    int n;
    cin >> n;
    int a[n];
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int cnt = 0;
//    cout << "b={";
    for (int i = 1; i < n; ++i) {
      s.insert(a[i-1]);
      auto it = upper_bound(s.begin(), s.end(), a[i]);

      cnt += distance(s.begin(), it);
//      cout << distance(s.begin(), it) << ", ";
    }
//    cout << "}";
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
