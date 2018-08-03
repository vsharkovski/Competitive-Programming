#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;


void main1() {

  int n;
  cin >> n;
  vector<int> v(n);
  int minv = 1e9+1;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    minv = min(minv, v[i]);
  }
  int pos = minv%n;
  int t = minv;
  v[pos] -= t;
  if (v[pos] <= 0) {
    if (pos+1 == n) cout << 1;
    else cout << pos+1;
    return;
  }
  do {
    t++;
    pos = (pos+1)%n;
    v[pos] -= t;
  } while (v[pos] > 0);
  cout << pos+1 << endl;

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
