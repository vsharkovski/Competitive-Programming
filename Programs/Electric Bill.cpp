#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;


int paytocwh(int p) {
  int c = 0;
  if (p >= 200) {
    c += 100;
    p -= 200;
  } else {
    return c + p/2;
  }
  if (p >= 3*9900) {
    c += 9900;
    p -= 3*9900;
  } else {
    return c + p/3;
  }
  if (p >= 5*990000) {
    c += 990000;
    p -= 5*990000;
  } else {
    return c + p/5;
  }
  return c + p/7;
}

int cwhtopay(int c) {
  int p = 0;
  if (c >= 100) {
    p += 2*100;
    c -= 100;
  } else {
    return p + 2*c;
  }
  if (c >= 9900) {
    p += 3*9900;
    c -= 9900;
  } else {
    return p + 3*c;
  }
  if (c >= 990000) {
    p += 5*990000;
    c -= 990000;
  } else {
    return p + 5*c;
  }
  return p + 7*c;
}


void solve() {

  int a, b;

  while (cin >> a >> b, a != 0 && b != 0) {

    int totalcwh = paytocwh(a);
    // me, neighbour
    // $(M) + $(N) = $A
    // M + N = totalcwh <-- BING BING BING

    int low = 0, high = totalcwh, m;
    while (low <= high) {
      m = (low+high)/2;
      int n = cwhtopay(totalcwh - m);
      int diff = n - cwhtopay(m);
      if (diff > b) {
        low = m;
      } else if (diff < b) {
        high = m;
      } else {
        break;
      }
    }

    cout << cwhtopay(m) << endl;

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
