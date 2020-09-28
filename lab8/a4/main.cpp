#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& used, vector<int>& comp, int n, int comp_id, int i){
    for (int j = 0; j < graph[i].size(); ++j) {
        if(!used[graph[i][j]]) {
            used[graph[i][j]] = true;
            comp[graph[i][j]] = comp_id;
            dfs(graph, used, comp, n, comp_id, graph[i][j]);
        }
    }
}

int main() {
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph;
    vector<bool> used;
    vector<int> comp;
    for (int l = 0; l < n; ++l) {
        graph.push_back(vector<int>());
        used.push_back(false);
        comp.push_back(0);
    }
    int i, j;
    for (int k = 0; k < m; ++k) {
        cin >> i >> j;
        graph[i - 1].push_back(j - 1);
        graph[j - 1].push_back(i - 1);
    }
    int comp_id = 1;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            comp[i] = comp_id;
            used[i] = true;
            dfs(graph, used, comp, n, comp_id, i);
            comp_id++;
        }
    }
    cout << comp_id - 1<< "\n";
    for (int i = 0; i < n; ++i) {
        cout << comp[i] << " ";
    }
    return 0;
}