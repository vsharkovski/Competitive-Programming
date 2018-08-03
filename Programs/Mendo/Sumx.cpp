#include <iostream>
#include <set>
#include <map>
using namespace std;
 
class Solution {
private:
    int N;
    int X;
    set<int> s;
    int sz = 0;
    map<int, set<int>> m;
public:
    Solution() {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            int a; cin >> a;
            s.insert(a);
        }
        cin >> X;
 
        for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
            int a = *it; //prviot broj
            int b = X - a; //drugiot broj
            if (s.find(b) != s.end()) {
                if (a > b) { int t = b; a = b; b = t; } //a<b sekogas
                if (m[a].find(b) == m[a].end()) { //parov ne e seuste najden
                    m[a].insert(b);
                    sz++;
                }
            }
        }
 
        sz /= 2; //better than fixing the above code, right? :^)
        cout << sz;
    }
};
 
int main() {
    Solution s;
}
