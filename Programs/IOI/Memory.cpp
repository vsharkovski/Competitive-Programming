#include "grader.h"
#include "memory.h"
#include <bits/stdc++.h>
using namespace std;


void play() {
  vector<int> pos[200] = {};
  for (int i = 1; i <= 50; ++i) {
    char ch = faceup(i);
    pos[(int)ch].push_back(i);
  }
  for (char ch = 'A'; ch <= 'Y'; ++ch) {
    faceup(pos[ch][0]);
    faceup(pos[ch][1]);
  }
}
