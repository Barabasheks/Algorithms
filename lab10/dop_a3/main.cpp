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
    vector <vector<pair<int,int>>> graph(n, vector<pair<int, int>>());
    int ver1, ver2, distance;
    for (int i = 0; i < m; ++i) {
        cin >> ver1 >> ver2 >> distance;
        graph[ver1 - 1].push_back(pair<int, int>(ver2 - 1, distance));
        graph[ver2 - 1].push_back(pair<int, int>(ver1 - 1, distance));
    }

    long long sum_dist = 0;
    vector<int> min_distances(n, 100000001), used(n, 0);
    min_distances[0] = 0;
    set<pair<int, int>> queue;
    for (int i = 0; i < n; ++i) {
        queue.insert(pair<int, int>(min_distances[i], i));
    }
    while(!queue.empty()){
        int v = queue.begin()->second;
        sum_dist += queue.begin()->first;
        queue.erase(pair<int, int>(queue.begin()->first, v));
        used[v] = 1;
        for (int i = 0; i < graph[v].size(); ++i) {
            int to = graph[v][i].first;
            int size = graph[v][i].second;
            if (min_distances[to] > size && used[to] == 0){
                queue.erase (pair<int, int>(min_distances[to], to));
                min_distances[to] = size;
                queue.insert (pair<int, int>(min_distances[to], to));
            }
        }
    }
    cout << sum_dist;
    return 0;
}
