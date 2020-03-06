inline int add(int x, int y) {
	x += y;
	if (x >= mod) x -= mod;
	if (x < 0) x += mod;
	return x;
}

inline int mult(int x, int y) {
	return (long long)x * y % mod;
}

int power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mult(res, a);
		a = mult(a, a);
		b /= 2;
	}
	return res;
}

int modular_inverse(int a) {
	return power(a, mod-2); // mod is prime
}
