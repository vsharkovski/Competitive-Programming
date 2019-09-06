const int maxn = 2e5;

struct LiChaoTree {
    typedef int ftype;
    typedef complex<ftype> point;
    #define x real
    #define y imag
    // Dot product
    ftype dot(point a, point b) {
        return (conj(a) * b).x();
    }
    // Value of a function at some point
    ftype f(point a, ftype x) {
        return dot(a, {x, 1});
    }
    point line[4*maxn];
    // Add a function (line)
    void add_line(point nw, int v = 1, int tl = 0, int tr = maxn) {
        int tm = (tl + tr) / 2;
        bool lef = f(nw, tl) < f(line[v], tl);
        bool mid = f(nw, tm) < f(line[v], tm);
        if (mid) {
            swap(nw, line[v]);
        }
        if (tl+1 < tr) {
            if (lef != mid) {
                add_line(nw, 2*v, tl, tm);
            } else {
                add_line(nw, 2*v+1, tm, tr);
            }
        }
    }
    // Get minimum of all functions at point x
    int get(int x, int v = 1, int tl = 0, int tr = maxn) {
        int tm = (tl + tr) / 2;
        if (tl+1 == tr) {
            return f(line[v], x);
        } else if (x < tm) {
            return min(f(line[v], x), get(x, 2*v, tl, tm));
        } else {
            return min(f(line[v], x), get(x, 2*v+1, tm, tr));
        }
    }
};
