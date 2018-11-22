#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;


#define x first
#define y second
typedef pair<double, double> dd;

inline double euclid(const dd& p1, const dd& p2) {
  return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

struct yComp {
  bool operator () (const dd& a, const dd &b) const {
    return a.y < b.y;
  }
};

void Solve() {
  int n;
  cin >> n;

  vector<dd> points(n);
  for (int i = 0; i < n; ++i) {
    cin >> points[i].x >> points[i].y;
  }
  sort(points.begin(), points.end());

  double d = 1e9;
  int j = 0;
  set<dd, yComp> s;
  s.insert(points[0]);

  for (int i = 1; i < n; ++i) {
    while (j < i && points[i].x - points[j].x > d) {
      s.erase(points[j]);
      ++j;
    }
    for (auto it = s.lower_bound(ii(points[i].x-d, points[i].y-d));
              it != s.end() && it->y <= points[i].y+d;
              ++it) {
      d = min(d, euclid(points[i], *it));
    }
    s.insert(points[i]);
  }

  cout << setprecision(2) << fixed << d << endl;
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
