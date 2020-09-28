#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("pathsg.in", "r", stdin);
    freopen("pathsg.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    const int inf = INT_MAX;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph (n, vector<int>(n, inf));
    int ver1, ver2, cost;
    for (int i = 0; i < m; ++i) {
        cin >> ver1 >> ver2 >> cost;
        graph[ver1 - 1][ver2 - 1] = cost;
    }
    for (int i = 0; i < n; ++i) {
        graph[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
        int s = k;
        vector<long long> dist(n);
        for (int i = 0; i < n; ++i) {
            dist[i] = graph[s][i];
        }
        vector<char> used(n, 0);
        dist[s] = 0;
        used[s] = 1;
        for (int i = 0; i < n - 1; ++i) {
            int v = -1;
            for (int j = 0; j < n; ++j) {
                if ((not used[j]) and ((v == -1) or (dist[v] > dist[j])))
                    v = j;
            }
            used[v] = 1;
            for (int j = 0; j < n; ++j) {
                if (dist[j] > dist[v] + graph[v][j])
                    dist[j] = dist[v] + graph[v][j];
            }
        }
        for (int l = 0; l < n; ++l) {
            cout << dist[l] << " ";
        }
        cout << endl;
    }
    return 0;
}