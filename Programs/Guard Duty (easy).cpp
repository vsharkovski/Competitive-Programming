#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point { int i; int x; int y; };

bool isintersecting(point& p1, point& p2, point& q1, point& q2) { //https://stackoverflow.com/users/14637/thomas
    return (((q1.x-p1.x)*(p2.y-p1.y) - (q1.y-p1.y)*(p2.x-p1.x))
            * ((q2.x-p1.x)*(p2.y-p1.y) - (q2.y-p1.y)*(p2.x-p1.x)) < 0)
            &&
           (((p1.x-q1.x)*(q2.y-q1.y) - (p1.y-q1.y)*(q2.x-q1.x))
            * ((p2.x-q1.x)*(q2.y-q1.y) - (p2.y-q1.y)*(q2.x-q1.x)) < 0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int r, b;
    cin >> r >> b;
    vector<point> rebels(r), bases(b);
    for (int i = 0; i < r; ++i) {
        cin >> rebels[i].x >> rebels[i].y;
        rebels[i].i = i;
    }
    for (int i = 0; i < b; ++i) {
        cin >> bases[i].x >> bases[i].y;
        bases[i].i = i;
    }
    if (r != b) {
        cout << "No";
        return 0;
    }

    do {
        bool ok = 1;
        for (int i = 0; i < r && ok; ++i) {
            for (int j = i+1; j < r && ok; ++j) {
                if (isintersecting(rebels[i], bases[i], rebels[j], bases[j])) {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok) {
            cout << "Yes";
            return 0;
        }
    } while (next_permutation(rebels.begin(), rebels.end(), [](point &p1, point &p2){
                                  return p1.i < p2.i;
                              }));

    cout << "No";

}
