#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <set>
#include <queue>
#include <utility>
using namespace std;


class Ship2048
{
  public:
    vector<string> grid;
    int R, C;
    void up() {
        for (int c = 0; c < C; ++c) {
            for (int r = 0; r < R; ++r) {
                if (grid[r][c] == '1') {
                    int r1 = r;
                    while (r1 > 0 && grid[r1-1][c] == '0') {
                        --r1;
                    }
                    swap(grid[r][c], grid[r1][c]);
                }
            }
        }
    }
    void down() {
        for (int c = 0; c < C; ++c) {
            for (int r = R-1; r >= 0; --r) {
                if (grid[r][c] == '1') {
                    int r1 = r;
                    while (r1+1 < R && grid[r1+1][c] == '0') {
                        ++r1;
                    }
                    swap(grid[r][c], grid[r1][c]);
                }
            }
        }
    }
    void left() {
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] == '1') {
                    int c1 = c;
                    while (c1 > 0 && grid[r][c1-1] == '0') {
                        --c1;
                    }
                    swap(grid[r][c], grid[r][c1]);
                }
            }
        }
    }
    void right() {
        for (int r = 0; r < R; ++r) {
            for (int c = C-1; c >= 0; --c) {
                if (grid[r][c] == '1') {
                    int c1 = c;
                    while (c1+1 < C && grid[r][c1+1] == '0') {
                        ++c1;
                    }
                    swap(grid[r][c], grid[r][c1]);
                }
            }
        }
    }
    string KthRow(vector<string> cannonBalls, string tilts, int N, int K)
    {
        grid = cannonBalls;
        R = grid.size();
        C = grid[0].size();
        for (int i = 0; i < tilts.size(); ++i) {
            char ch = tilts[i];
            if (ch == 'F') {
                up();
            } else if (ch == 'B') {
                down();
            } else if (ch == 'L') {
                left();
            } else if (ch == 'R') {
                right();
            }
        }
        return grid[K];
    }
};
