#include <iostream>
#include <set>
 
using namespace std;
 
int main() {
    int n, k1;
    cin >> n >> k1;
 
    int k2 = n - k1;
 
    set<int> tezini;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        tezini.insert(t);
    }
 
    int K1_smallest;
    int K2_largest;
 
    set<int>::reverse_iterator rit = tezini.rbegin();
    for (int i = 0; i < k1 - 1; ++i) { ++rit; }
    K1_smallest = *rit;
    ++rit;
    K2_largest = *rit;
 
    int xNum = K1_smallest - K2_largest;
    cout << xNum << endl;
}