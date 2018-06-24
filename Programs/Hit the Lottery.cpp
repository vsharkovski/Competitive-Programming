#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;


void main1() {

  int n;
  cin >> n;
  int m = n/100;
  n %= 100;
  while (n > 0) {
    if (n >= 20) {
      n -= 20;
      m++;
    } else if (n >= 10) {
      n -= 10;
      m++;
    } else if (n >= 5) {
      n -= 5;
      m++;
    } else {
      m += n;
      n = 0;
    }
  }
  cout << m << endl;



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
