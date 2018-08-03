#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <bitset>

#define endl '\n'
#define EPS 1e-9

using namespace std;
typedef long long ll;
typedef std::pair<int, int> pii;



void SOLVE() {

  int numwords, maxlines, maxchars;
  while (cin >> numwords >> maxlines >> maxchars) {

//    cout << "---------------------------------\n";

    int pages = 1, lines = 0, chars = 0;

    for (int i = 0; i < numwords; ++i) {
      string word;
      cin >> word;

      int len = word.length();
      int newchars = chars + len + !!(chars>0);

      if (newchars > maxchars) {
        lines++;
        chars = len;
        if (lines == maxlines) {
          lines = 0;
          pages++;
//          cout << "\n----";
        }
//        cout << "\n" << word;

      } else {
//        if (chars>0) cout << " ";
        chars = newchars;
//        cout << word;
      }
    }

//    cout << endl << " ## PAGES: ";

    cout << pages << endl;

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
















