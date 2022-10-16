#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int B = 105;
const int M = 20;

int numTopics;
int books;
int minutes[B];
int topics[B];
int cur[1 << M], nxt[1 << M];

int getTopicId(string t) {
    static map<string, int> ids;
    auto ptr = ids.find(t);
    if (ptr == ids.end()) {
        int sz = ids.size();
        ids[t] = sz;
        numTopics = sz+1;
        return sz;
    } else {
        return ptr->second;
    }
}

int main() {
    // read input
    string line;
    books = 0;
    numTopics = 0;
    while (getline(cin, line)) {
        stringstream ss(line);
        ss >> minutes[books];
        topics[books] = 0;
        string topic;
        while (ss >> topic) {
            topics[books] |= (1 << getTopicId(topic));
        }
        // cout << "book " << books << ", minutes=" << minutes[books] << " topics=" << bitset<M>(topics[books]) << endl;
        ++books;
    }
    // do dp
    for (int m = 0; m < (1 << numTopics); ++m) {
        cur[m] = inf;
        nxt[m] = inf;
    }
    cur[0] = 0;
    for (int i = 0; i < books; ++i) {
        for (int m = 0; m < (1 << numTopics); ++m) {
            if (cur[m] == inf) {
                // haven't reached this state, skip
                continue;
            }
            // skip book
            nxt[m] = min(nxt[m], cur[m]);
            // use book
            nxt[m | topics[i]] = min(nxt[m | topics[i]], cur[m] + minutes[i]);
        }
        // update cur, nxt
        for (int m = 0; m < (1 << numTopics); ++m) {
            // if (nxt[m] != inf) {
            //     cout << "after first " << i << " books, m=" << bitset<M>(m) << " t=" << nxt[m] << endl;
            // }
            cur[m] = nxt[m];
            nxt[m] = inf;
        }
    }
    // print ans
    cout << cur[(1 << numTopics) - 1] << endl;
}
