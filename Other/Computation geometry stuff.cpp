/*
Magnitude of cross product of 2 vectors
If the angle between them is x, then 
m = 0         ==> x = 0 or 180
m is positive ==> 0 < x < 180
m is negative ==> 180 < x < 360

We are assuming both vectors start at (0, 0). Otherwise, see:
https://en.wikipedia.org/wiki/Cross_product#Computational_geometry
*/

inline ll prod(const pii& a, const pii& b) {
	return (ll)a.first*b.second - (ll)a.second*b.first;
}

/*
Sort points counter-clockwise
*/

sort(points.begin(), points.end(), [&](const pii& a, const pii& b) {
    int aUp = (a.second > 0) || (a.second == 0 && a.first > 0);
    int bUp = (b.second > 0) || (b.second == 0 && b.first > 0);
    if (aUp && !bUp) return true;
    if (!aUp && bUp) return false;
    ll vp = prod(a, b);
    if (vp > 0) return true;
    return false;
});
