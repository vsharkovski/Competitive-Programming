#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    double di;
    cin >> n >> di;
    double d = 1 - (di / 100);
 
    set<int> proizvodi;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        proizvodi.insert(x);
    }
 
    int i = 0;
    double cvk = 0;
    while (proizvodi.empty() == false) {
        double c;
        if ((i+1)%3 == 0) {
            c = (*proizvodi.rbegin()) * d;
            proizvodi.erase(prev(proizvodi.end()));
        }
        else {
            c = *proizvodi.begin();
            proizvodi.erase(proizvodi.begin());
        }
        cvk += c;
        //cout << "i:" << i << " c:" << c << endl;
        i++;
    }
 
    cout << setprecision(2) << fixed << cvk << endl;
}