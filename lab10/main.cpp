#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, ver1, ver2;
    cin >> n >> m;
    vector<vector<int>> graph (n, vector<int>());
    for (int i = 0; i < m; ++i) {
        cin >> ver1 >> ver2;
        graph[ver1 - 1].push_back(ver2 - 1);
        graph[ver2 - 1].push_back(ver1 - 1);
    }
    for (int i = 0; i < n; ++i) {
        cout << graph[i].size() << " ";
    }
    return 0;
}
