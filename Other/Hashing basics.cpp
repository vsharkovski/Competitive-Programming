////////////////
// One modulo //
////////////////

const ll M = 1e9 + 9, P = 9973; // Change M and P if you want to

ll pw[100001]; // Stores the powers of P modulo M

int n;
string s;
ll hsh[100001];

void calc_hashes() {
	hsh[0] = 1;
	for (int i = 0; i < n; ++i) {
		hsh[i+1] = ((hsh[i]*P)%M + s[i]) % M;
	}
}

ll get_hash(int a, int b) {
	return (hsh[b+1] - (hsh[a] * pw[b-a+1]) % M + M) % M;
}

//////////////////////
// Multiple modulos //
//////////////////////
