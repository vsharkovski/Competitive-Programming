void z_algorithm(string& s, vector<int>& z) {
	int n = s.length();
	z.resize(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		z[i] = max(0, min(z[i-l], r-i+1));
		while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
			l = i;
			r = i + z[i];
			++z[i];
		}
	}
}
