#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
////	freopen("output.txt", "w", stdout);
//#endif

    int n, k;
    cin >> n >> k;
    while (k--) {
        if (n % 10 == 0) {
            n /= 10;
        } else {
            n--;
        }
    }
    cout << n;
}
