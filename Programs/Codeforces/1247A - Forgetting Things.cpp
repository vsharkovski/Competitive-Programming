#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int da, db;
	cin >> da >> db;
	if (da == db) {
		cout << da << 0 << ' ' << db << 1 << endl;
	} else if (da+1 == db) {
		cout << da << ' ' << db << endl;
	} else if (da == 9 && db == 1) {
		cout << da << ' ' << db << 0 << endl;
	} else {
		cout << -1 << endl;
	}
}
