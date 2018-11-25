#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;


void theirturn();

int n, m;
bool taken[2002] = {};
vector<ii> powers;
vector<int> myorder;

int forcednext = -1;
int turn = 0;
int idx = 0;

void myturn() {
  if (turn == 2*n) return;
  ++turn;
  if (forcednext == -1) {
    while (idx < 2*n && taken[myorder[idx]]) {
      ++idx;
    }
    if (idx == 2*n) {
      cout << -1 << endl; return;
    }
    taken[myorder[idx]] = 1;
    cout << myorder[idx] + 1 << endl;
    cout.flush();
  } else {
    taken[forcednext] = 1;
    cout << forcednext + 1 << endl;
    cout.flush();
    forcednext = -1;
  }
  theirturn();
}

void theirturn() {
  if (turn == 2*n) return;
  ++turn;
  int x;
  cin >> x;
  if (x == -1) {
    cout << -1 << endl; return;
  }
  --x;
  taken[x] = 1;
  if (powers[x].second != -1 && !taken[powers[x].second]) {
    forcednext = powers[x].second;
  }
  myturn();
}

void Solve() {
  cin >> n >> m;
  for (int i = 0; i < 2*n; ++i) {
    int p;
    cin >> p;
    powers.emplace_back(p, -1);
    myorder.push_back(i);
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    powers[a].second = b;
    powers[b].second = a;
  }
  sort(myorder.begin(), myorder.end(), [&](int &x, int &y) {
    if (powers[x].second != -1 && powers[y].second == -1) {
      return true;
    } else if (powers[x].second == -1 && powers[y].second != -1) {
      return false;
    } else {
      return powers[x].first > powers[y].first;
    }
  });

  int t;
  cin >> t;
  if (t == 1) {
    myturn();
  } else {
    theirturn();
  }
}



int main() {
//  std::ios::sync_with_stdio(false);
//  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  Solve();
}
