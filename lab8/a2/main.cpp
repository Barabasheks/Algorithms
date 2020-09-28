#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int matrix[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (matrix[i][j] != matrix[j][i] || (i == j && matrix[i][j] == 1)) {
                cout << "NO";
                flag = false;
                break;
            }
        }
    }
    if (flag)
        cout << "YES";
    return 0;
}