#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;




void _initialize();
int main() {
  _initialize();

  string ns;
  while (cin >> ns, ns != "0") {

    int n = 0;
    for (int i = 0; i < ns.length()-1; ++i) n = 10*n + (ns[i]-'0');

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    bool go = 1;

    for (int j = 1; j < n-1 && go; ++j) {
      set<int> difs;
      for (int i = 0; i < j; ++i) {
        difs.insert(abs(a[j]-a[i]));
      }
      for (int k = j+1; k < n; ++k) {
        if (difs.count( abs(a[k]-a[j]) )) {
          go = 0;
        }
      }
    }


    if (go) cout << "yes\n"; else cout << "no\n";
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
