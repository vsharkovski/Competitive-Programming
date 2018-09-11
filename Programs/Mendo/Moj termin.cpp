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






int L;

int a[102];
int numdone = 0;

void bf(int i, int group, int rem) {
  if (numdone > 1) return;
  if (i == L) {
    if (rem == 0) {
      ++numdone;
    }
    return;
  }
  if (rem > 0) {
    if (a[i] == -1 || a[i] == group) {
      bf(i+1, group, rem-1);
    }
  } else { // rem = 0
    if (a[i] != -1) {
      bf(i+1, a[i], a[i]-1);
    } else {
      for (int g = 1; g <= L-i; ++g) {
        bf(i+1, g, g-1);
      }
    }
  }
}


void Solve() {
  cin >> L;
  string s;
  for (int i = 0; i < L; ++i) {
    cin >> s;
    if (s == "N") {
      a[i] = -1;
    } else {
      a[i] = stoi(s);
    }
  }
  bf(0, -1, 0);
  if (numdone == 1) {
    cout << "DA\n";
  } else {
    cout << "NE\n";
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


















