#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
template <class Key, class Compare = less<Key>> // find_by_order, order_of_key (for multiset: pair(val, time of insertion))
using Tree = tree<Key, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;




// how many lectures we can get for each student if we have this many students
ll getlectures(ll numdays, ll class1, ll class2, ll students) {
  class1 = min(class1, students);
  class2 = min(class2, students);
  ll slots = class1 * (numdays / 2 + (numdays % 2)) + class2 * (numdays / 2);
  return slots / students;
}

void _SOLVE_() {
  ll totalstudents, numdays, class1, class2, minlectures;
  cin >> totalstudents >> numdays >> class1 >> class2 >> minlectures;
  // numdays = numlectures (1 lecture per day)
  ll low = 1, high = totalstudents, students, lectures, ans = 0;
  while (low <= high) {
    students = (low + high) / 2;
    lectures = getlectures(numdays, class1, class2, students);
    if (lectures >= minlectures) {
      ans = students;
      low = students + 1;
    } else {
      high = students - 1;
    }
  }
  cout << ans << endl;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifdef _DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  _SOLVE_();
}
