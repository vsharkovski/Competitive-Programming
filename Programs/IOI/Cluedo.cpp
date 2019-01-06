#include "grader.h"
#include "cluedo.h"
#include <bits/stdc++.h>
using namespace std;

void Solve() {
  int m = 1, l = 1, w = 1;
  while (1) {
    int t = Theory(m, l, w);
    if (t == 0) {
      return;
    }
    if (t == 1) ++m;
    else if (t == 2) ++l;
    else if (t == 3) ++w;
  }
}
