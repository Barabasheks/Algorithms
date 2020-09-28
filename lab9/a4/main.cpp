#include <iostream>
#include <vector>

using namespace std;

void dfs1 (int v, bool* used, vector<vector<int>>& graph, vector<int>& order) {
    used[v] = true;
    for (size_t i=0; i<graph[v].size(); ++i)
        if (!used[ graph[v][i] ])
            dfs1 (graph[v][i], used, graph, order);
    order.push_back (v);
}

void dfs2 (int v, bool* used, vector<vector<int>>& transposed_graph, vector<int>& component, int num_comp) {
    used[v] = true;
    component[v] = num_comp;
    for (size_t i=0; i<transposed_graph[v].size(); ++i)
        if (!used[transposed_graph[v][i]])
            dfs2 (transposed_graph[v][i], used, transposed_graph, component, num_comp);
}

int main() {
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector <vector<int>> graph (n, vector<int>()), transposed_graph(n, vector<int>());
    bool* used = new bool[n];
    vector<int> order, component(n);
    int ver1, ver2;
    for (int i = 0; i < m; ++i) {
        cin >> ver1 >> ver2;
        graph[ver1 - 1].push_back (ver2 - 1);
        transposed_graph[ver2 - 1].push_back (ver1 - 1);
    }

    for (int i = 0; i < n; ++i) {
        used[i] = false;
    }
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs1 (i, used, graph, order);
    for (int i = 0; i < n; ++i) {
        used[i] = false;
    }
    int num_comp = 0;
    for (int i = n - 1; i >= 0 ; --i) {
        int v = order[i];
        if (!used[v]) {
            num_comp++;
            dfs2 (v, used, transposed_graph, component, num_comp);
        }
    }
    cout << num_comp << endl;
    for (int i = 0; i < n; ++i) {
        cout << component[i] << " ";
    }
    return 0;
}