#include <iostream>
#include <vector>

using namespace std;

bool dfs(int ver, vector<vector<int>>& graph, vector<int>& cycle, int* used){
    used[ver] = 1;
    cycle.push_back(ver);
    for (int i = 0; i < graph[ver].size(); ++i) {
        int to = graph[ver][i];
        if (used[to] == 1){
            for (int j = 0; j < cycle.size(); ++j) {
                if (cycle[j] == to){
                    cout << "YES" << endl;
                    int k = j + 1;
                    cout << to + 1 << " ";
                    while(cycle[k] != to && k < cycle.size()) {
                        cout << cycle[k] + 1 << " ";
                        k++;
                    }
                    break;
                }
            }
            return false;
        }
        if (used[to] == 0){
            bool circle = dfs(to, graph, cycle, used);
            if (!circle){
                return false;
            }
        }
    }
    cycle.pop_back();
    used[ver] = 2;
    return true;
}

int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
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

    vector<int> cycle;
    bool cycle_bool = true;
    for (int j = 0; j < n; ++j) {
        if (used[j] == 0 && cycle_bool)
            cycle_bool = dfs(j, graph, cycle, used);
    }
    if (cycle_bool){
        cout << "NO";
    }
    return 0;
}
