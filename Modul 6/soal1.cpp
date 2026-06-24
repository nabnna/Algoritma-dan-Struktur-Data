#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<char> vertices(N);
    int charToIndex[256];
    for (int i = 0; i < 256; i++) {
        charToIndex[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        cin >> vertices[i];
        charToIndex[vertices[i]] = i;
    }

    int M;
    cin >> M;

    vector<vector<int>> adjMatrix(N, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;

        int u_idx = charToIndex[u];
        int v_idx = charToIndex[v];
        
        if (u_idx != -1 && v_idx != -1) {
            adjMatrix[u_idx][v_idx] = w;
        }
    }

    cout << "Adjacency Matrix:\n";
    cout << " ";
    for (int i = 0; i < N; i++) {
        cout << " " << vertices[i];
    }
    cout << "\n";

    for (int i = 0; i < N; i++) {
        cout << vertices[i];
        for (int j = 0; j < N; j++) {
            cout << " " << adjMatrix[i][j];
        }
        cout << "\n";
    }

    return 0;
}