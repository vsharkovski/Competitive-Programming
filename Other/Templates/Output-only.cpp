#include <bits/stdc++.h>
using namespace std;



void solve(ifstream& in, ofstream& out) {

}

int main() {
    int tests = 10;
    for (int i = 1; i <= tests; ++i) {
        stringstream ss;
        ss << setfill('0') << setw(2) << i;
        string test_name = ss.str();
        string in_full = "input/" + test_name + ".in";
        string out_full = "output/" + test_name + ".out";
        ifstream in(in_full);
        ofstream out(out_full);
        if (in.good()) {
            solve(in, out);
        } else {
            cout << "Problem reading " << in_full << "\n";
        }
        in.close();
        out.close();
    }
}
