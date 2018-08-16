#include <bits/stdc++.h>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;

const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){ if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}






void Solve() {
  string a[3];
  int reallen[3], succ[3];

  cin >> a[0];
  a[2] = a[1] = a[0];

  int len = a[0].length();
  int sum = 0;
  vi pos[3];

  for (int i = 0; i < len; ++i) {
    int d = (a[0][i] - '0') % 3;
    sum = (sum + d) % 3;
    pos[d].push_back(i);
  }
  for (int i = 0; i < 3; ++i) {
    sort(all(pos[i]), greater<int>());
  }

//  cout << a[0] << "\n---\n";

  succ[0] = 0;
  if (sum == 0) {
    succ[0] = 1;
  } else if (sum == 1) {
    if (pos[1].size() >= 1) {
      a[0][pos[1][0]] = 'x';
      succ[0] = 1;
    } else if (pos[2].size() >= 2) {
      a[0][pos[2][0]] = a[0][pos[2][1]] = 'x';
      succ[0] = 1;
    }
  } else { // sum = 2 mod 3
    if (pos[2].size() >= 1) {
      a[0][pos[2][0]] = 'x';
      succ[0] = 1;
    } else if (pos[1].size() >= 2) {
      a[0][pos[1][0]] = a[0][pos[1][1]] = 'x';
      succ[0] = 1;
    }
  }

  int sum1 = sum;
  for (int i = 0; i < pos[1].size() && sum1 > 0; ++i) {
    a[1][pos[1][i]] = 'x';
    sum1 = (sum1 - 1 + 3) % 3;
  }
  for (int i = 0; i < pos[2].size() && sum1 > 0; ++i) {
    a[1][pos[2][i]] = 'x';
    sum1 = (sum1 - 2 + 3) % 3;
  }
  succ[1] = sum1 == 0;

  sum1 = sum;
  for (int i = 0; i < pos[2].size() && sum1 > 0; ++i) {
    a[2][pos[2][i]] = 'x';
    sum1 = (sum1 - 2 + 3) % 3;
  }
  for (int i = 0; i < pos[1].size() && sum1 > 0; ++i) {
    a[2][pos[1][i]] = 'x';
    sum1 = (sum1 - 1 + 3) % 3;
  }
  succ[2] = sum1 == 0;

//  cout << a[0] << "\n" << a[1] << "\n" << a[2] << "\n";
//  cout << "\n\n";

  for (int i = 0; i < 3; ++i) {
    if (!succ[i]) {
      reallen[i] = -2e9;
      continue;
    }
    reallen[i] = 0;
    bool printed = 0, allx = 1;
    for (int j = 0; j < len; ++j) {
      if (a[i][j] == 'x') continue;
      allx = 0;
      if (printed || a[i][j] != '0') {
        printed = 1;
        ++reallen[i];
      }
    }
    if (allx) reallen[i] = -2e9;
    else if (!printed) reallen[i] = 0;
  }

  if (reallen[0] == -2e9 && reallen[1] == -2e9 && reallen[2] == -2e9) {
    cout << -1;
  } else {
    int brl = reallen[0], i = 0;
    for (int j = 1; j < 3; ++j) if (reallen[j] > brl) brl = reallen[j], i = j;

    if (reallen[i] == 0) cout << 0;
    else {
      bool printed = 0;
      for (int j = 0; j < len; ++j) {
        if (a[i][j] == 'x') continue;
        if (printed || a[i][j] != '0') {
          printed = 1;
          cout << a[i][j];
        }
      }
    }
  }


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








