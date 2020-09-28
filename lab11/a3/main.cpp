#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    freopen("pathbgep.in", "r", stdin);
    freopen("pathbgep.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    const long long inf = INT_MAX;
    int n, s, m;
    cin >> n >> m;
    s = 0;
    vector<vector<pair<int, int>>> graph (n, vector<pair<int, int>>());
    int ver1, ver2, cost;
    for (int i = 0; i < m; ++i) {
        cin >> ver1 >> ver2 >> cost;
        graph[ver1 - 1].push_back(make_pair(ver2 - 1, cost));
        graph[ver2 - 1].push_back(make_pair(ver1 - 1, cost));
    }
    vector<long long> dist (n, inf);
    set<pair<int, int>> queue;
    for (int i = 0; i < graph[0].size(); ++i) {
        dist[graph[0][i].first] = graph[0][i].second;
        queue.insert(make_pair(graph[0][i].second, graph[0][i].first));
    }
    vector<char> used (n, 0);
    dist[s] = 0;
    used[s] = 1;
    cost = - 1;
    for (int i = 0; i < n - 1; ++i) {
        int v = -1;
        while (v == -1 or dist[v] != cost){
            v = queue.begin()->second;
            cost = queue.begin()->first;
            queue.erase(make_pair(cost, v));
        }
        used[v] = 1;
        for (int j = 0; j < graph[v].size(); ++j) {
            int key = graph[v][j].first;
            int cost = graph[v][j].second;
            if (dist[key] > dist[v] + cost) {
                dist[key] = dist[v] + cost;
                queue.insert(make_pair(dist[key], key));
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        cout << dist[k] << " ";
    }
    return 0;
}