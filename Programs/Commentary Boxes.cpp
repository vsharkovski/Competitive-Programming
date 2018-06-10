#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    long long n, m, a, b;
    cin >> n >> m >> a >> b;

    long long r = n % m;
    cout << min(r*b, (m-r)*a);

}
