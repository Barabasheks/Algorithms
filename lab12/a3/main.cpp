#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int inc_flow(vector<vector<int>> &graph, vector<vector<int>> &flows, vector<vector<int>>& decomp_without_cycle) {
    const int INF = INT_MAX;
    int n = graph.size();
    vector<int> parents (n, -1);
    vector<int> cur_flow(n, 0);
    queue<int> queue;
    queue.push(0);
    cur_flow[0] = INF;

    while ((parents[n - 1] == -1) && (!queue.empty())) {
        int current = queue.front();
        queue.pop();
        for (int i = 0; i < n; i++) {
            if ((current != i) && (parents[i] == -1) && (graph[current][i] - flows[current][i] > 0)) {
                queue.push(i);
                parents[i] = current;
                if (cur_flow[current] <= graph[current][i] - flows[current][i])
                    cur_flow[i] = cur_flow[current];
                else
                    cur_flow[i] = graph[current][i] - flows[current][i];
            }
        }
    }

    if (parents[n - 1] == -1)
        return 0;

    vector<int> dec_flow;
    dec_flow.push_back(cur_flow[n - 1]);
    int current = n - 1;
    while (current != 0) {
        flows[parents[current]][current] += cur_flow[n - 1];
        flows[current][parents[current]] -= cur_flow[n - 1];
        dec_flow.push_back(current);
        current = parents[current];
    }
    dec_flow.push_back(0);
    decomp_without_cycle.push_back(dec_flow);
    return cur_flow[n - 1];
}

bool dfs (int v, vector<vector<pair<int, int>>>& graph_list, vector<vector<int>>& flows, vector<char>& color, vector<int>& parent, int& cycle_st, int& cycle_end) {
    color[v] = 1;
    for (int i = 0; i < graph_list[v].size(); ++i) {
        int to = graph_list[v][i].first;
        if (flows[v][to] < graph_list[v][to].second) {
            if (color[to] == 0) {
                parent[to] = v;
                if (dfs(to, graph_list, flows, color, parent, cycle_st, cycle_end))
                    return true;
            } else if (color[to] == 1) {
                cycle_end = v;
                cycle_st = to;
                return true;
            }
        }
    }
    color[v] = 2;
    return false;
}

int main()
{
    freopen("decomposition.in", "r", stdin);
    freopen("decomposition.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<vector<int>> flows(n, vector<int>(n, 0));
    vector<vector<int>> decomp_without_cycle;
    vector<vector<int>> edges(n, vector<int>(n, -1));
    vector<vector<pair<int, int>>> graph_list (n, vector<pair<int, int>>());
    int ver1, ver2, capacity;
    int k = 0;
    for (int i = 0; i < m; i++) {
        k++;
        cin >> ver1 >> ver2 >> capacity;
        graph[ver1 - 1][ver2 - 1] += capacity;
        edges[ver1 - 1][ver2 - 1] = k;
        graph_list[ver1 - 1].push_back(make_pair(ver2 - 1, capacity));
    }

    while (true) {
        int add_flow = inc_flow(graph, flows, decomp_without_cycle);
        if (add_flow <= 0)
            break;
    }
    cout << decomp_without_cycle.size() << "\n";
    for (int i = 0; i < decomp_without_cycle.size(); ++i) {
        int size = decomp_without_cycle[i].size();
        cout << decomp_without_cycle[i][0] << " " << size - 2 << " ";
        for (int j = size - 1; j > 1 ; --j) {
            ver1 = decomp_without_cycle[i][j];
            ver2 = decomp_without_cycle[i][j - 1];
            cout << edges[ver1][ver2] << " ";
        }
        cout << "\n";
    }

    for (int v = 0; v < n; v++) {
        vector<char> color(n, 0);
        vector<int> parent(n, -1);
        vector<int> cycle;
        int cycle_st = 0, cycle_end;
        if (dfs(v, graph_list, flows, color, parent, cycle_st, cycle_end)) {
            cycle.push_back(cycle_st);
            for (int vi = cycle_end; vi != cycle_st; vi = parent[vi])
                cycle.push_back(vi);
            cycle.push_back(cycle_st);
            reverse(cycle.begin(), cycle.end());
            vector<int> cycle_edges;
            int min_flow = 1e9;
            for (int j = 0; j < cycle.size() - 1; ++j){
                cycle_edges.push_back(edges[cycle[j]][cycle[j + 1]]);
                if (graph[cycle[j]][cycle[j + 1]] - flows[cycle[j]][cycle[j + 1]] < min_flow){
                    min_flow = graph[cycle[j]][cycle[j + 1]] - flows[cycle[j]][cycle[j + 1]];
                }
            }
            for (int j = 0; j < cycle.size() - 1; ++j){
                flows[cycle[j]][cycle[j + 1]] += min_flow;
                flows[cycle[j + 1]][cycle[j]] -= min_flow;
            }
            cout << min_flow << " " << cycle_edges.size();
            for (int k = 0; k < cycle_edges.size(); ++k) {
                cout << cycle_edges[k];
            }
            cout << endl;
        }
    }
    return 0;
}