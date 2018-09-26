ll _sieve_size = 1e7;
bitset<100010> bs;
vi primes;

void sieve(ll upperbound) {
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 1;
  for (ll i = 2; i <= _sieve_size; ++i) {
    if (bs[i]) {
      for (ll j = i*i; j <= _sieve_size; j += i) {
        bs[j] = 0;
      }
      primes.push_back(i);
    }
  }
}

vi primeFactors(ll x) {
  vi factors;
  for (ll pf_idx = 0, pf = primes[pf_idx];
       pf_idx < _sieve_size && pf * pf <= x;
       ++pf_idx, pf = primes[pf_idx]) {
    while (x % pf == 0) {
      x /= pf;
      factors.push_back(pf);
    }
  }
  if (x != 1) factors.push_back(x);
  return factors;
}
