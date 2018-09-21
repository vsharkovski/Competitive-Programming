long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  while (b) {
    if (b & 1)
      res = res * (a % mod);
    a = a * (a % mod);
    b = b >> 1;
  }
  return res;
}
