#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, p;
    cin >> n >> p;
    int a[n];
    ll s[n];
    cin >> a[0];
    s[0] = a[0];
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    ll bestsum = -1;
    for (int i = 0; i < n; ++i) {
        ll s1 = s[i], s2 = s[n-1] - s1;
        bestsum = max(bestsum, s1%p + s2%p);
    }
    cout << bestsum;

}
