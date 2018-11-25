#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;




int match[100][100] = {};
int n;
string s;

int dp[200][200];

int F(int i, int j) {
  if (i + 1 >= j)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  int res = match[s[i]][s[j]] + F(i+1, j-1);
  for (int k = i; k < j; ++k)
    res = max(res, F(i, k) + F(k+1, j));
  return dp[i][j] = res;
}

void Solve() {
  match['A']['U'] = match['U']['A'] = 1;
  match['C']['G'] = match['G']['C'] = 1;
  match['G']['U'] = match['U']['G'] = 1;
  cin >> n >> s;
  memset(dp, -1, sizeof(dp));
  cout << F(0, n-1) << endl;
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
