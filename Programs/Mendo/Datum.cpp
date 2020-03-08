#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int days[3] = {31, 30, 31};
    int m = 0;
    int d = 7;
    while (n > 0) {
        --n;
        ++d;
        if (d > days[m]) {
            d = 1;
            ++m;
        }
    }
    cout << d << ". ";
    string candy[3] = {"mart", "april", "maj"};
    cout << candy[m];
}
