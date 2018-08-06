#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <complex>
#include <functional>
#include <utility>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <bitset>
#include <sstream>

#define endl '\n'
#define EPS 1e-9
#define all(v) begin(v), end(v)

using namespace std;
typedef long long ll;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;
typedef std::vector<int> vi;



void MAIN() {

  set<string> dictionary;
  string word;

  while (cin >> word, word != "#") {
    dictionary.insert(word);
  }

  string cypher;
  getline(cin, cypher);
  getline(cin, cypher);
  int len = cypher.length();

  int best_score = 0;
  string best_str = cypher;

  for (int k = 0; k < 26; ++k) {
    for (int i = 0; i < len; ++i) {
      if (cypher[i] == ' ') cypher[i] = 'A';
      else if (cypher[i] == 'Z') cypher[i] = ' ';
      else cypher[i] = cypher[i]+1;
    }
    int score = 0;
    stringstream ss(cypher);
    while (ss >> word) {
      if (dictionary.count(word)) ++score;
    }
    if (score > best_score) {
      score = best_score;
      best_str = cypher;
    }
  }

  stringstream ans(best_str);
  int linelen = 0;
  while (ans >> word) {
    if (linelen + word.length() > 60) {
      linelen = 0;
      cout << '\n';
    }
    if (linelen > 0) {
      linelen += 1;
      cout << ' ';
    }
    linelen += word.length();
    cout << word;
  }
  cout << endl;


}




int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  #ifdef _DEBUG
  std::freopen("in.txt", "r", stdin);
  std::freopen("out.txt", "w", stdout);
  #endif
  MAIN();
}













