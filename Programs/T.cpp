#include <iostream>
#include <vector>
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
 
int main() {
    //N is the number of episodes, M is the watch time available
    int n, m;
    cin >> n >> m;
 
    vector<int> episodes(n);
 
    for (int i = 0; i < n; ++i) {
        cin >> episodes[i];
    }
 
    int max_watched = 0, end = 0, sum = 0;
 
    for (int start = 0; start < n; ++start) {
        while (end < n && sum + episodes[end] <= m) {
            sum += episodes[end];
            end++;
        }
        if (end - start > max_watched) {
            max_watched = end - start;
        }
        sum -= episodes[start];
    }
 
    cout << max_watched << endl;
}