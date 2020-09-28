#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    const long long INF = 2e18;
    int n, m, s, ver1, ver2;
    long long cost;
    cin >> n >> m >> s;
    vector<vector<long long>> graph (m, vector<long long>(3));
    for (int i = 0; i < m; ++i) {
        cin >> ver1 >> ver2 >> cost;
        graph[i][0] = ver1 - 1;
        graph[i][1] = ver2 - 1;
        graph[i][2] = cost;
    }

    vector<pair<long long, int>> dist (n, pair<long long, int>(INF, 0));
    vector<int> parent (n, -1);
    dist[s - 1].first = 0;
    int v;
    for (int i = 0; i < n; ++i) {
        v = -1;
        for (int j = 0; j < m; ++j) {
            if (dist[graph[j][0]].first != INF && dist[graph[j][1]].first > dist[graph[j][0]].first + graph[j][2]) {
                dist[graph[j][1]].first = max(-INF, dist[graph[j][0]].first + graph[j][2]);
                parent[graph[j][1]] = graph[j][0];
                v = graph[j][1];
            }
        }
    }

    if (v == -1) {
        for (int i = 0; i < n; ++i) {
            if (dist[i].first != INF)
                cout << dist[i].first << endl;
            else
                cout << "*" << endl;
        }
    }
    else {
        for (int i = 0; i < n; ++i)
            v = parent[v];
        dist[v].second = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dist[graph[j][0]].second == 1)
                    dist[graph[j][1]].second = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (dist[i].first == INF)
                cout << "*" << endl;
            else if (dist[i].second != 0)
                cout << "-" << endl;
            else
                cout << dist[i].first << endl;
        }
    }
    return 0;
}
