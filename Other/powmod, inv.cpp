const ll mod = 1e9 + 7;


// fast modular exponentiation

ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}


// modular multiplicative inverse
// gcd(a, M) = 1 necessary
// a ^ (phi(M) - 1) = 1 (mod M) ;; phi is Euler totient function
// if M is prime, phi(M) = M-1
// ==> a ^ (M - 2) = 1 (mod M)

ll inv(ll a) {
  return powmod(a, mod - 2);
}
