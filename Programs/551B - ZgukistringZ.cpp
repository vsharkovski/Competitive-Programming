#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



typedef vector<int> vi;

void makecnt(string& s, vi& cnt) {
    cnt.resize(26);
    for (char ch : s) {
        ++cnt[int(ch-'a')];
    }
}

bool candecrease(vi& c1, vi& c2, int num) {
    for (int i = 0; i < (int)c1.size(); ++i) {
        if (c1[i] < c2[i]*num) {
            return false;
        }
    }
    return true;
}

void decrease(vi& c1, vi& c2, int num) {
    for (int i = 0; i < (int)c1.size(); ++i) {
        c1[i] -= c2[i]*num;
    }
}

int maxpossible(vi& c1, vi& c2) {
    int res = 1e9;
    for (int i = 0; i < (int)c1.size(); ++i) {
        if (c2[i] > 0) {
            if (c1[i] < c2[i]) {
                res = 0;
                break;
            } else {
                res = min(res, c1[i] / c2[i]);
            }
        }
    }
    return res;
}

void offload(vi& c, string& s) {
    for (int i = 0; i < (int)c.size(); ++i) {
        char ch = 'a' + i;
        while (c[i]--) {
            s += ch;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    string a, b, c;
    cin >> a >> b >> c;

    vi cnta, cntb, cntc, cnttemp;

    makecnt(a, cnta);
    makecnt(b, cntb);
    makecnt(c, cntc);

    int ans = 0, fnumb = 0, fnumc = 0;

    for (int numb = 0; true; ++numb) {
        cnttemp = cnta;
        if (candecrease(cnttemp, cntb, numb) == false) {
            break;
        }
        decrease(cnttemp, cntb, numb);
        int numc = maxpossible(cnttemp, cntc);
        int res = numb + numc;
        if (res > ans) {
            ans = res;
            fnumb = numb;
            fnumc = numc;
        }
    }

    cnttemp = cnta;
    decrease(cnttemp, cntb, fnumb);
    decrease(cnttemp, cntc, fnumc);
    while (fnumb--) {
        cout << b;
    }
    while (fnumc--) {
        cout << c;
    }
    for (int i = 0; i < 26; ++i) {
        char ch = 'a' + i;
        while (cnttemp[i]--) {
            cout << ch;
        }
    }
    cout << '\n';

}
