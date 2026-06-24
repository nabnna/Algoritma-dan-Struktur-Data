#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<char> vertices(N);
    bool isValid[256] = {false}; 
    
    for (int i = 0; i < N; i++) {
        cin >> vertices[i];
        isValid[vertices[i]] = true; 
    }

    vector<vector<int>> adjMatrix(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    cout << "Adjacency List:\n";
    for (int i = 0; i < N; i++) {
        cout << vertices[i] << " -> ";
        
        bool hasEdge = false;
        bool isFirstEdge = true; 

        for (int j = 0; j < N; j++) {
            int weight = adjMatrix[i][j];

            if (weight > 0) {
                // Validasi array boolean
                if (isValid[vertices[i]] && isValid[vertices[j]]) {
                    if (!isFirstEdge) {
                        cout << ", ";
                    }
                    cout << "(" << vertices[j] << "," << weight << ")";
                    
                    hasEdge = true;
                    isFirstEdge = false;
                }
            }
        }

        if (!hasEdge) {
            cout << "-";
        }
        cout << "\n";
    }

    return 0;
}