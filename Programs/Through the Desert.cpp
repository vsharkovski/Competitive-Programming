#include <bits/stdc++.h>
#define endl '\n'
#define EPS 1e-9
typedef long long ll;
using namespace std;

/*
0: goal
1: fuel consumption
2: leak
3: gas station
4: mechanic
*/

struct Ev {
  int id;
  int pos;
  int n;
};

vector<Ev> events;

bool can(double x) {
  double v = x;
  int ppos = 0, leaks = 0;
  double nperkm = 0;
  for (Ev e : events) {
    int dist = e.pos - ppos;
    v -= nperkm*double(dist) + leaks*dist;
    if (v < 0) {
      return false;
    } else if (e.id == 0) {
      return true;
    } else if (e.id == 1) {
      nperkm = e.n / 100.0;
    } else if (e.id == 2) {
      leaks++;
    } else if (e.id == 3) {
      v = x;
    } else if (e.id == 4) {
      leaks = 0;
    }
    ppos = e.pos;
  }
  return true;
}


void solve() {

  string _a, _b;
  Ev e;

  while (cin >> e.pos >> _a >> _b >> e.n, e.n > 0) {
    events.clear();
    e.id = 1;
    events.push_back(e);
    while (cin >> e.pos >> _a) {
      if (_a == "Goal") {
        e.id = 0;
        events.push_back(e);
        break;
      } else if (_a == "Fuel") {
        cin >> _b >> e.n;
        e.id = 1;
        events.push_back(e);
      } else if (_a == "Leak") {
        e.id = 2;
        events.push_back(e);
      } else if (_a == "Gas") {
        cin >> _b;
        e.id = 3;
        events.push_back(e);
      } else if (_a == "Mechanic") {
        e.id = 4;
        events.push_back(e);
      }
    }

    double lo = 0.0, hi = 10000.0, mid = 0.0, ans = 0.0;
    while (abs(hi-lo) > EPS) {
      mid = (lo + hi) / 2.0;
      if (can(mid)) {
        ans = mid;
        hi = mid;
      } else {
        lo = mid;
      }
    }

    cout << setprecision(3) << fixed << ans << endl;
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
