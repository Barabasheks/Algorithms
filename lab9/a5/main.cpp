#include <iostream>
#include <vector>

using namespace std;

void dfs(int ver, vector<vector<int>>& graph, vector<int>& topsort, int* used){
    used[ver] = 1;
    for (int i = 0; i < graph[ver].size(); ++i) {
        int to = graph[ver][i];
        if (used[to] == 0){
            dfs(to, graph, topsort, used);
        }
    }
    topsort.push_back(ver);
    used[ver] = 2;
}

int main() {
    freopen("hamiltonian.in", "r", stdin);
    freopen("hamiltonian.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, ver1, ver2;
    cin >> n >> m;
    vector<vector<int>> graph;
    int* used = new int [n];
    for (int l = 0; l < n; ++l) {
        graph.push_back(vector<int>());
        used[l] = 0;
    }
    for (int i = 0; i < m; ++i) {
        cin >> ver1 >> ver2;
        graph[ver1 - 1].push_back(ver2 - 1);
    }

    vector<int> topsort;
    for (int j = 0; j < n; ++j) {
        if (used[j] == 0)
            dfs(j, graph, topsort, used);
    }
    bool path = false;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < graph[topsort[i]].size(); ++j) {
            path = path || (topsort[i - 1] == graph[topsort[i]][j]);
        }
        if (!path && i != 0){
            break;
        }
        path = i == 0;
    }
    if (path)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
