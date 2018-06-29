#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;


int n;
vector<int> v;

bool can(int k) {
  int h = 0;
  for (int i = 0; i < n; ++i) {
    int diff = v[i] - h;
    if (diff > k) {
      return false;
    }
    if (diff == k) {
      h += diff;
      k--;
    } else {
      h += diff;
    }
  }
  return true;
}


void solve() {

  int T;
  cin >> T;
  for (int _t = 0; _t < T; ++_t) {

    cin >> n;
    v.resize(n);

    int low = 1e9, high = -1;

    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      high = max(high, v[i]);
      low = min(low, v[i]);
    }

    int mid, k;
    while (high >= low) {
      mid = (low+high) / 2;
      if (can(mid)) {
        k = mid;
        high = mid-1;
      } else {
        low = mid+1;
      }
    }

    if (can(k-1)) k = k-1;

    cout << "Case " << _t+1 << ": " << k << endl;


  }

}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  solve();
}
