#include <bits/stdc++.h>
using namespace std;

struct coor { int x; int y; };
int counter = 0;

inline int distsq(coor Q, coor W) {
    return (Q.x-W.x)*(Q.x-W.x) + (Q.y-W.y)*(Q.y-W.y);
}

void test(coor A, coor B, coor C) {
    int aa = distsq(B, C), bb = distsq(C, A), cc = distsq(A, B);
    if (aa + bb == cc) {
        counter++;
    }
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    vector<coor> v(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v[i].x = x;
        v[i].y = y;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                test(v[i], v[j], v[k]);
                test(v[i], v[k], v[j]);
                test(v[k], v[i], v[j]);
                test(v[k], v[j], v[i]);
                test(v[j], v[k], v[i]);
                test(v[j], v[i], v[k]);
            }
        }
    }
    cout << counter/2;
}
