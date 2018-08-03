long long C(int n, int k) {
  static const int cMAXN = 60;
  static long long cdp[cMAXN][cMAXN];
  static bool cfirstCall = true;
 
  if (cfirstCall) cfirstCall = false, memset(cdp, -1, sizeof(cdp));
  
  if (n < k) return 0;
  if (k == 0 || n == k) return 1;
  if (cdp[n][k] != -1) return cdp[n][k];
  return cdp[n][k] = C(n-1, k-1) + C(n-1, k);
}
