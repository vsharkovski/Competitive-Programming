#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;






struct Event {
  ll d;
  int i, type;
  Event(ll D, int I, int T) : d(D), i(I), type(T) {}
  Event() {}
  bool operator < (const Event &rhs) const {
    return d != rhs.d ? d < rhs.d : type < rhs.type;
  }
};

void Solve() {
  int R, C, N, B;
  cin >> R >> C >> N >> B;

  vector<Event> horev, vertev;

  for (int i = 0; i < B; ++i) {
    int r, c;
    cin >> r >> c;
    ll r0 = max(1, r - N), c0 = max(1, c - N);
    ll r1 = min(R, r + N) + 1, c1 = min(C, c + N) + 1;
    horev.emplace_back(c0, i, 0);
    horev.emplace_back(c1, i, 1);
    vertev.emplace_back(r0, i, 0);
    vertev.emplace_back(r1, i, 1);
  }
  sort(horev.begin(), horev.end());
  sort(vertev.begin(), vertev.end());

  ll sum = 0;
  bool active[102] = {};
  ll prevc = -1;

  for (Event &e1 : horev) {
    ll c = e1.d;
    ll linelength = 0;
    ll prevr = -1;
    int numoverlapping = 0;

    for (Event &e2 : vertev) {
      if (active[e2.i] == 0) continue;
      ll r = e2.d;
      if (e2.type == 0)
        ++numoverlapping;
      if (numoverlapping > 0 && prevr != -1)
        linelength += r - prevr;
      if (e2.type == 1)
        --numoverlapping;
      prevr = r;
      if (numoverlapping == 0)
        prevr = -1;
    }
    if (prevc != -1111)
      sum += (c - prevc) * linelength;
      
    prevc = c;
    if (e1.type == 0)
      active[e1.i] = 1;
    else
      active[e1.i] = 0;
  }

  cout << sum << endl;


}



int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  Solve();
}
