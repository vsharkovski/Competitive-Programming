#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll impossible = -2;
const int N = 16;

ll p10[N];

int n, A, CA, B, CB;
int num[N];
ll dp[N+1][N+1][N+1][2][2];
// bigger: if there is some i s.t. i-th digit was bigger than num[i]

ll dfs(int i, int ca, int cb, int bigger, int started) {
	ll &res = dp[i][ca][cb][bigger][started];
	if (res != -1)
		return res;
	if (i == n)
		return res = (ca >= CA && cb >= CB) ? 0 : impossible;
	res = impossible;
	for (int d = 0; d <= 9; ++d) {
		if (d < num[i] && !bigger)
			continue;
		int ca1 = (d == A) ? ca+1 : ca;
		int cb1 = (d == B) ? cb+1 : cb;
		int started1 = started || (d > 0);
		if (d == 0 && A == 0 && !started)
			--ca1;
		int bigger1 = bigger || (d > num[i]);
		ll res1 = dfs(i+1, ca1, cb1, bigger1, started1);
		if (res1 == impossible)
			continue;
		res1 = p10[i]*d + res1;
		if (res == impossible || res1 < res)
			res = res1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	cin >> str;
	n = str.length();
	for (int i = 0; i < n; ++i)
		num[i] = str[i] - '0';
	cin >> A >> B >> CA >> CB;
	if (A > B) {
		swap(A, B);
		swap(CA, CB);
	}
	//cout<<"A="<<A<<" CA="<<CA<<" B="<<B<<" CB="<<CB<<"\n";
	reverse(num, num+n);
	for (int i = n; i < N; ++i)
		num[i] = 0; // add leading zeros
	n = N;
	reverse(num, num+n);
	p10[0] = 1;
	for (int i = 1; i < n; ++i)
		p10[i] = p10[i-1] * 10;
	reverse(p10, p10+n);
	//cout<<"num: ";for (int i = 0; i < n; ++i)cout<<num[i];cout<<'\n';
	memset(dp, -1, sizeof(dp));
	ll ans = dfs(0, 0, 0, 0, 0);
	cout << ans << '\n';
}
