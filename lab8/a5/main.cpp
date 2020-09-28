#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    freopen("pathbge1.in", "r", stdin);
    freopen("pathbge1.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph;
    vector<bool> used;
    vector<int> way;
    for (int l = 0; l < n; ++l) {
        graph.push_back(vector<int>());
        used.push_back(false);
        way.push_back(0);
    }
    int i, j;
    for (int k = 0; k < m; ++k) {
        cin >> i >> j;
        graph[i - 1].push_back(j - 1);
        graph[j - 1].push_back(i - 1);
    }
    queue<int> queue;
    queue.push(0);
    used[0] = true;
    while (!queue.empty()){
        int this_node = queue.front();
        queue.pop();
        for (int i = 0; i < graph[this_node].size(); ++i) {
            int to = graph[this_node][i];
            if(!used[to]) {
                queue.push(to);
                used[to] = true;
                way[to] = way[this_node] + 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << way[i] << " ";
    }
    return 0;
}