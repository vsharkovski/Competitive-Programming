#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
 
int main() {
    int a1, a2, a3, a4; cin >> a1 >> a2 >> a3 >> a4;
    map<int,int> m;
    m[a1]++; m[a2]++; m[a3]++; m[a4]++;
    cout << 4 - max(m[0], m[5]);
}