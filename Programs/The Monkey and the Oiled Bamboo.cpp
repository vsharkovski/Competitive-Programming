#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;

// Couldn't do it with binary searchio

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

    int high = -1;
    int prev = 0;

    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      high = max(high, v[i]-prev);
      prev = v[i];
    }

    if (!can(high)) high++;
    cout << "Case " << _t+1 << ": " << high << endl;


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
