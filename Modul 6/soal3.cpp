#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct State {
    int r, c, dist;
};

int main() {
    int R, C;
    if (!(cin >> R >> C)) return 0;

    vector<vector<int>> grid(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int SR, SC, FR, FC;
    cin >> SR >> SC >> FR >> FC;

    queue<State> q;
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    q.push({SR, SC, 0});
    visited[SR][SC] = true;

    int shortestPath = -1;

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        if (curr.r == FR && curr.c == FC) {
            shortestPath = curr.dist;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if (grid[nr][nc] == 0 && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc, curr.dist + 1});
                }
            }
        }
    }

    cout << shortestPath << "\n";

    return 0;
}