#include <bits/stdc++.h>
using namespace std;
  
int main()
{
    int n, m;
    cin >> n >> m;
    int lvl = 0;
  
    while (m >= n) {
        m -= n;
        m += 3;
        lvl++;
    }
  
    cout << lvl;
}