void LIS(vector<int> &a, vector<int> &L) {
  int n = a.size();
  L.clear();
  vector<int>::iterator it;
  for (int i = 0; i < n; ++i) {
    it = lower_bound(L.begin(), L.end(), a[i]);
    if (it == L.end()) {
      L.push_back(a[i]);
    } else {
      *it = min(*it, a[i]);
    }
  }
}
