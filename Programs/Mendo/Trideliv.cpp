#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
 
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    string n;
    cin >> n;
 
    int sum = 0;
    for (int i = 0; i < n.length(); ++i) {
        sum += n[i] - '0';
        sum %= 3;
    }
 
    for (int i = 0; i < n.length(); ++i) {
        for (char ch = '9'; ch > n[i]; --ch) {
            if ((sum - (n[i] - '0') + (ch - '0') + 3) % 3 == 0) {
                n[i] = ch;
                cout << n;
                return 0;
            }
        }
        if (i+1 == n.length()) {
            for (char ch = n[i]-1; ch >= '0'; --ch) {
                if ((sum - (n[i] - '0') + (ch - '0') + 3) % 3 == 0) {
                    n[i] = ch;
                    cout << n;
                    return 0;
                }
            }
        }
    }
 
}
