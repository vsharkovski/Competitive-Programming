#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    long long n;
    cin >> n;
    if (n==0) cout << 0;
    else if (n&1) cout << (n+1)/2;
    else cout << n+1;
}
