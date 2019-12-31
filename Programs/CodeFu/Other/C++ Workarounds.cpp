string ToString(double a) {
    stringstream ss;
    ss << fixed;
    ss.precision(2);
    ss << a;
    return ss.str();
}

double ToDouble(string s) {
    double res = 0;
    double cnt = 1;
    bool founddot = false;
    for (char& ch : s) {
        if (ch == '.') {
            founddot = true;
        } else {
            if (founddot) {
                cnt *= 10;
            }
            res = (10 * res) + double(ch - '0');
        }
    }
    res /= cnt;
    return res;
}
