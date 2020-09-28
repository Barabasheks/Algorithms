#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    freopen("spantree3.in", "r", stdin);
    freopen("spantree3.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector <vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
    int ver1, ver2, distance;
    for (int i = 0; i < m; ++i) {
        cin >> ver1 >> ver2 >> distance;
        graph[ver1 - 1].push_back(pair<int, int>(ver2 - 1, distance));
        graph[ver2 - 1].push_back(pair<int, int>(ver1 - 1, distance));
    }

    unsigned long long sum_dist = 0;
    vector<int> min_distances (n, 10000001);
    min_distances[0] = 0;
    set<pair<int, int>> queue;
    queue.insert(pair<int, int>(0, 0));
    for (int i = 0; i < n; ++i) {
        int v = queue.begin()->second;
        sum_dist += queue.begin()->first;
        queue.erase (queue.begin());
        for (int j = 0; j < graph[v].size(); ++j) {
            int to = graph[v][j].first;
            if (graph[v][j].second < min_distances[to]) {
                queue.erase (pair<int, int>(min_distances[to], to));
                min_distances[to] = graph[v][j].second;
                queue.insert (pair<int, int>(min_distances[to], to));
            }
        }
    }
    cout << sum_dist;
    return 0;
}
