#include <bits/stdc++.h>
using namespace std;
 
const int M = 1000000;
 
int main() {
//    std::ios::sync_with_stdio(false);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    int x = n%6;
    int cnt = x == 0 ? 1 : x;
    while (x < n) {
        x += 6;
        cnt = (cnt + x) % M;
    }
    cout << cnt;
}
