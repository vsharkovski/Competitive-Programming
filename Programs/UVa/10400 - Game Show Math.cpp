#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <sstream>

#define endl '\n'
#define EPS 1e-9

using namespace std;
typedef long long ll;
typedef std::pair<int, int> pii;


const int OFS = 32000;


int n, m; //num. numbers, target
int numbers[105];

int dp[105][2*OFS+5];
char path[105][2*OFS+5];

bool test(int i, int num) {
  if (i == n) return num == m;
  
  int& ref = dp[i][num+OFS];
  if (ref != -1) return ref;
  
  char& pref = path[i][num+OFS];
  ref = 0;
  int num1, x = numbers[i];
  
  num1 = num+x;
  if (abs(num1) < OFS) {
    ref = test(i+1, num1);
    if (ref) {
      pref = '+';
      return 1;
    }
  }
  num1 = num-x;
  if (abs(num1) < OFS) {
    ref = test(i+1, num1);
    if (ref) {
      pref = '-';
      return 1;
    }
  }
  num1 = num*x;
  if (abs(num1) < OFS) {
    ref = test(i+1, num1);
    if (ref) {
      pref = '*';
      return 1;
    }
  }
  num1 = num/x;
  if (num % x == 0 && abs(num1) < OFS) {
    ref = test(i+1, num1);
    if (ref) {
      pref = '/';
      return 1;
    }
  }
  return 0;
}   


void SOLVE() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> numbers[i];
    }
    cin >> m;
    
    memset(dp, -1, sizeof(dp));
    memset(path, 0, sizeof(path));
    
    bool has = test(0, 0);
    if (!has) {
      cout << "NO EXPRESSION\n"; 
    } else {

      int num = numbers[0], x;
      cout << num;
      
      for (int i = 1; i < n; ++i) {
        char ch = path[i][num+OFS];
        x = numbers[i];
        if (ch == '+') {
          num += x;
        } else if (ch == '-') {
          num -= x;
        } else if (ch == '*') {
          num *= x;
        } else {
          num /= x;
        }
        cout << ch << x;
      }
    
      cout << "=" << m << endl;
      
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
  SOLVE();
}



















