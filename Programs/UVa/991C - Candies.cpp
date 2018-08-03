#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;


inline bool dobro(ll k, ll n) {
  ll ima = 0, n0 = n;
  while (n > 0) {
    ima += min(n, k);
    n = n-k - (n-k)/10;
  }
  return ima + ima >= n0;
}

void main1() {

  ll n;
  cin >> n;

  ll low = 0, high = n;

  // Binary search!
  while (high > low+1) {
    ll sredina = (low+high)/2;
    if (dobro(sredina, n)) {
      high = sredina;
    } else {
      low = sredina;
    }
  }

  cout << high << endl;

}






int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  main1();
}
