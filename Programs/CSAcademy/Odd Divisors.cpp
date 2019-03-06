#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;




ll sumodd(ll n) { // sum of odd numbers from 1 to n
    ll numodd = n / 2 + (n % 2);
    return numodd*numodd; // sum of first x odd numbers = x^2
}

ll sum(ll n) { // problem statement from 1 to n
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return sumodd(n) + sum(n / 2);
    }
}

void Main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << sum(b) - sum(a-1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Main();
}
