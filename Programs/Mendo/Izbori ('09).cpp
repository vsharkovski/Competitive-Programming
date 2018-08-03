#include <bits/stdc++.h>
using namespace std;
 
struct kr {
    int i = 0, a = 0, b = 0;
    kr(int I, int A, int B) : i(I), a(A), b(B) {};
};
 
bool S1(const kr &a, const kr &b) {
    return a.a > b.a;
}
bool S2(const kr &a, const kr &b) {
    return a.b > b.b;
}
 
int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
 
    int n, k;
    cin >> n >> k;
 
    vector<kr> v;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back(kr(i, a, b));
    }
//    for (kr z : v) {
//        cout << z.i << ' ';
//    } cout << endl;
    sort(v.begin(), v.end(), S1);
//    for (kr z : v) {
//        cout << z.i << ' ';
//    } cout << endl;
    sort(v.begin(), v.begin()+k, S2);
//    for (kr z : v) {
//        cout << z.i << ' ';
//    } cout << endl;
 
    cout << v[0].i+1 << endl;
}
