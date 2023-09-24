#include <bits/stdc++.h>
using namespace std;

const int MAX_SQRT = ceil(sqrt(1e9)) + 1;

vector<int> primes;
bitset<MAX_SQRT> isComposite;

void sieve() {
	for (int i = 2; i < MAX_SQRT; i++) {
		if (isComposite[i]) continue;

		primes.push_back(i);

		for (int j = i*i; j < MAX_SQRT; j += i) {
			isComposite[j] = true;
		}
	}
}

bool solve(int n) {
	int nDPD = 0;
	
	for (int p : primes) {
		if (p*p > n) break;

		if (n % p == 0) {
			nDPD++;
			while (n % p == 0) {
				n /= p;
			}
		}
	}

	if (n > 1) {
		nDPD += 1;
	}

  return nDPD > 1;
}

int main() {
	sieve();

	int T, n;
	
	cin >> T;
	while (cin >> n) {
		cout << (solve(n) ? "Yes" : "No") << endl;
	}
}
