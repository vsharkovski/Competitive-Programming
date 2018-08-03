#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;


void _initialize();
int main() {
  _initialize();

  vector<string> a = {"00", "01", "81"};
  vector<string> b = {"0000", "0001", "2025", "3025", "9801"};
  vector<string> c = {"000000", "000001", "088209", "494209", "998001"};
  vector<string> d = {"00000000", "00000001", "04941729", "07441984", "24502500", "25502500", "52881984", "60481729", "99980001"};

  auto f = [](vector<string> &v) {
    for (string s : v) {
      cout << s << endl;
    }
  };

  int x;
  while (cin >> x) {
    if (x == 2) f(a);
    else if (x == 4) f(b);
    else if (x == 6) f(c);
    else if (x == 8) f(d);
  }

}




void _initialize() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
  #endif
}
