#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    int matrix[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = 0;
        }

    }
    int ki, kj;
    bool parallel_ribs = false;
    for (int k = 0; k < m; ++k) {
        cin >> ki >> kj;
        if (matrix[ki - 1][kj - 1] == 1 || matrix[kj - 1][ki - 1] == 1){
            cout << "YES";
            parallel_ribs = true;
            break;
        }
        matrix[ki - 1][kj - 1] = 1;
    }
    if (!parallel_ribs)
        cout << "NO";
}