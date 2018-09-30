ll extendedgcd(ll a, ll b, ll &x, ll &y) {
  if (a == 0) {
    x = 0, y = 1;
    return b;
  }
  ll x1, y1;
  ll g = extendedgcd(b%a, a, x1, y1);
  x = y1 - (b/a)*x1;
  y = x1;
  return g;
}

const ll NOSOLUTION = -1e17;

void diofantova(ll a, ll b, ll c, ll &x, ll &y) {
  // find x,y s.t. ax + by = c;
  ll g = extendedgcd(a, b, x, y);
  if (c % g != 0) {
    x = y = NOSOLUTION;
    return;
  }
  // find u,v s.t. a'u + b'u = gcd(a', b') = 1
  ll u, v;
  extendedgcd(a/g, b/g, u, v);
  x = u*c, y = v*c;
}
