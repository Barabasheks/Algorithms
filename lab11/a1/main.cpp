#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    const long long inf = LONG_LONG_MAX;
    int n, s, f;
    cin >> n >> s >> f;
    s = s - 1;
    f = f - 1;
    vector<vector<long long>> graph (n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == -1)
                graph[i][j] = inf;
        }
    }
    vector<long long> dist (n);
    for (int i = 0; i < n; ++i) {
        dist[i] = graph[s][i];
    }
    vector<char> used (n, 0);
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
            if (dist[j] > dist[v] + graph[v][j] and dist[v] != inf and graph[v][j] != inf)
                dist[j] = dist[v] + graph[v][j];
        }
    }
    if (dist[f] != inf)
        cout << dist[f];
    else
        cout << -1;
    return 0;
}