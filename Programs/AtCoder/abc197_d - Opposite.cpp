#include <bits/stdc++.h>
using namespace std;

typedef long double C;
typedef complex<C> P;
#define X real()
#define Y imag()
const C pi = acos(-1);
// arg(v) gives the angle of the vector w.r.t x-axis
// abs(v) gives the distance to the origin
// polar(distance, angle) gives complex coordinates

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	C n, x0, y0, xnd2, ynd2;
	cin >> n >> x0 >> y0 >> xnd2 >> ynd2;

	P p0 = {x0, y0};
	P pnd2 = {xnd2, ynd2};

	// the center point is between p0 and pn/2
	P center = {(p0.X + pnd2.X)/2.0, (p0.Y + pnd2.Y)/2.0};

	// translate the points so pc is at (0, 0)
	P p0t = p0 - center;

	// p1t is p0t but rotated by 2*pi/n counterclockwise
	P p1t = polar(abs(p0t), arg(p0t) + 2*pi/n);

	// translate back
	P p1 = p1t + center;

	cout << setprecision(10) << fixed;
	cout << p1.X << " " << p1.Y << "\n";
}
