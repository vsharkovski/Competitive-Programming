// Code written by: Vlatko, Yana

#include <bits/stdc++.h>
using namespace std;

const int C = 10000010;
const int N = 25;
const int P = 33554467;
const int M = 1e9 + 7;

int n, m, c;
int curr_state[N];
int next_state[N];
unordered_map<int, int> hashes;

inline int add(int x, int y) {
	x += y;
	if (x >= M) x -= M;
	if (x < 0) x += M;
	return x;
}

inline int mult(int x, int y) {
	return (long long)x * y % M;
}

inline int calc_hash() {
    int hash = 0;
    for (int i = 0; i < n; ++i) {
        hash = add(mult(hash, P), curr_state[i]);
    }
    return hash;
}

inline int get_cell(int i, int j){
    if (i < 0) i += n;
    if (i >= n) i -= n;
    if (j < 0) j += m;
    if (j >= m) j -= m;
    return (curr_state[i] >> j) & 1;
}

inline int alive_neighbours(int i, int j){
    int di[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int counter = 0;
    for (int k = 0; k < 8; k++){
        if(get_cell(i+di[k], j+dj[k])) {
            counter++;
        }
    }
    return counter;
}

void get_new_state(){
    for(int i = 0; i < n; i++){
        int new_row = 0;
        for(int j = 0; j < m; j++){
            int alive_neighb = alive_neighbours(i, j);
            if (get_cell(i, j) == 1 && (alive_neighb == 2 || alive_neighb == 3)){
                new_row |= (1 << j);
            } else if(get_cell(i, j) == 0 && alive_neighb == 3){
                new_row |= (1 << j);
            } else {
                new_row &= ~(1 << j);
            }
        }
        next_state[i] = new_row;
    }
    for (int i = 0; i < n; i++) {
        curr_state[i] = next_state[i];
    }
}

void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((curr_state[i] >> j) & 1) {
                cout << '*';
            } else {
                cout << '-';
            }
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m >> c;
    for (int i = 0; i < n; ++i) {
        curr_state[i] = 0;
        next_state[i] = 0;
        for (int j = 0; j < m; ++j) {
            char ch;
            cin >> ch;
            if (ch == '*') {
                curr_state[i] |= (1 << j);        
            }
        }
    }
    {
        int h = calc_hash();
        hashes[h] = 0;
        // cout << "iter=0 h=" << h << endl;
        // print();
    }
    for (int iter = 1; iter <= c; ++iter) {
        get_new_state();
        int h = calc_hash();
        // cout << "iter=" << iter << " h=" << h << endl;
        // print();
        auto ptr = hashes.find(h);
        if (ptr != hashes.end()) {
            int prev_iter = ptr->second;
            // cout << "!!! iter=" << iter << ", found previous iter=" << prev_iter << endl;
            int diff = iter - prev_iter;
            while (iter + diff <= c) {
                iter += diff;
            }
        } else {
            hashes[h] = iter;
        }
    }
    print();
}
