#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int potok(const int&);
int pobaraj(vector<int>& v1, vector<int>& v2);
 
int main() {
    int n;
    cin >> n;
 
    int a = 1, b = 3, c = 9;
 
    vector<int> vn = {n};
    vector<int> va = {a};
    vector<int> vb = {b};
    vector<int> vc = {c};
 
    int najdeno = -1, najdenoi = -1;
    int x = 0;
 
    while (najdeno == -1) {
        x = pobaraj(vn, va);
        if (x) {
            najdeno = 1;
            najdenoi = x;
            break;
        }
        x = pobaraj(vn, vb);
        if (x) {
            najdeno = 3;
            najdenoi = x;
            break;
        }
        x = pobaraj(vn, vc);
        if (x) {
            najdeno = 9;
            najdenoi = x;
            break;
        }
 
        n = potok(n);
        vn.push_back(n);
 
        a = potok(a);
        va.push_back(a);
 
        b = potok(b);
        vb.push_back(b);
 
        c = potok(c);
        vc.push_back(c);
    }
 
    cout << najdeno << ' ' << najdenoi << endl;
 
    return 0;
}
 
int potok(const int& x) {
    int sumaCifri = 0;
 
    int x1 = x;
    while (x1 != 0) {
        sumaCifri += x1 % 10;
        x1 /= 10;
    }
 
    return x + sumaCifri;
}
 
int pobaraj(vector<int>& v1, vector<int>& v2) {
    static vector<int> v_intersection;
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v_intersection));
 
    if (v_intersection.empty()) {
        return 0;
    } else {
        return v_intersection[0];
    }
};