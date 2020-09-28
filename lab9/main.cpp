#include <iostream>
#include <vector>

using namespace std;

bool dfs(int ver, vector<vector<int>>& graph, vector<int>& topsort, int* used){
    used[ver] = 1;
    for (int i = 0; i < graph[ver].size(); ++i) {
        int to = graph[ver][i];
        if (used[to] == 1){
            return false;
        }
        if (used[to] == 0){
            bool circle = dfs(to, graph, topsort, used);
            if (!circle){
                return false;
            }
        }
    }
    topsort.push_back(ver);
    used[ver] = 2;
    return true;
}

int main() {
    freopen("topsort.in", "r", stdin);
    freopen("topsort.out", "w", stdout);
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
    bool cycle = true;
    for (int j = 0; j < n; ++j) {
        if (used[j] == 0 && cycle)
            cycle = dfs(j, graph, topsort, used);
    }
    if (cycle){
        for (int k = n - 1; k >= 0 ; --k) {
            cout << topsort[k] + 1 << " ";
        }
    } else{
        cout << -1;
    }
    return 0;
}
