#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;


int main1() {

  int n;
  cin >> n;

  int n2 = n+n;
  vector<int> d(n2);
  for (int i = 0; i < n2; ++i) {
    cin >> d[i];
  }

  int cnt = 0;

  for (int i = 0; i < n2; i += 2) {
    int x = d[i];
    int j;
    for (j = i+1; j < n2; ++j) {
      if (d[j] == x) {
        break;
      }
    }
    for (j = j; j > i+1; --j) {
      swap(d[j], d[j-1]);
//      cout << "{"; for (int x : d) cout << x << ' '; cout << "}\n";
      cnt++;
    }

  }

  cout << cnt << endl;

  return 0;
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
