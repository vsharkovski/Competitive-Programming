#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

//
// This is a program that generates the numbers the main program uses
// ( Quirksome Squares.cpp )
//

void _initialize();
int main() {
  _initialize();

  auto f = [](int l, ll n) {
    string s = to_string(n);
    while (s.length() < l) {
      s = '0' + s;
    }
    int len = s.length();
    ll a = stoll(s.substr(0, len/2));
    ll b = stoll(s.substr(len/2, len));
    if ((a+b)*(a+b) == n) {
      cout << "\"" << s << "\", ";
    }
  };

  cout << "string a[] = {";
  for (ll i = 01; i <= 99; ++i) {
    f(2, i);
  }
  cout << "};" << endl;
  cout << "string b[] = {";
  for (ll i = 0001; i <= 9999; ++i) {
    f(4, i);
  }
  cout << "};" << endl;
  cout << "string c[] = {";
  for (ll i = 000001; i <= 999999; ++i) {
    f(6, i);
  }
  cout << "};" << endl;
  cout << "string d[] = {";
  for (ll i = 00000001; i <= 99999999; ++i) {
    f(8, i);
  }
  cout << "};" << endl;
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
