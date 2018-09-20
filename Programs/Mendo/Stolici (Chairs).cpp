#include <bits/stdc++.h>
using namespace std;
// printing
 
// typedefs
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;
// other
#define endl '\n'
#define all(v) begin(v), end(v)
const double EPS = 1e-9;
const ll mod = 1e9 + 7;
template<typename T> T gcd(T a, T b){T c; while(b){c=b; b=a%b; a=c;} return a;}
template<typename T> T powmod(T a, T b){T res = 1; a %= mod; while(b){if(b&1)res=res*(a%mod); a=a*(a%mod); b>>=1;} return res;}
 
 
 
 
inline int conv(string str) {
    int h = (str[0]-'0')*10 + (str[1]-'0');
    int m = (str[3]-'0')*10 + (str[4]-'0');
    int s = (str[6]-'0')*10 + (str[7]-'0');
    return h*60*60 + m*60 + s;
}
 
void Solve() {
    int N;
    cin >> N;
    int line[87000][2] = {};
 
    for (int i = 0; i < N; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        line[conv(s1)][0]++;
        line[conv(s2)][1]++;
    }
    int cnt = 0, ans = 0;
    for (int t = 0; t < 87000; ++t) {
        cnt += line[t][0];
        ans = max(ans, cnt);
        cnt -= line[t][1];
    }
    cout << ans << endl;
 
 
 
 
 
 
 
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
