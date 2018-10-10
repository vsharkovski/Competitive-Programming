#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
#include <functional>
#include <iterator>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>
#include <queue>
#include <deque>
#include <list>
#include <stack>
using namespace std;
// printing
// other
#define endl '\n'
#define all(v) begin(v), end(v)
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
const double EPS = 1e-9;
const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}












void Solve() {

  int N, M, L;
  cin >> N >> M >> L;
  
  int bestans = 2e9;
  string bestname = "";
  
  while (L--) {
    string name;
    int A, B;
    cin >> name >> A >> B;
    
    int dp[100055];
    for (int x = 0; x < M; ++x)
      dp[x] = 2e9;
    dp[M] = 0;
    for (int x = M+1; x <= N; ++x)
      dp[x] = min(A + dp[x-1], B + dp[x % 2 == 0 ? x/2 : x - (x+1)/2]);
    
    if (dp[N] < bestans) {
      bestans = dp[N];
      bestname = name;
    }
  }

  cout << bestname << " " << bestans << endl;


































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
