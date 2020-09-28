#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int INF = INT_MAX;

struct edge{
    int from, to, capacity, flow;
    edge* inv_e;
    edge(int from, int to, int capacity, int flow){
        this->from = from;
        this->to = to;
        this->capacity = capacity;
        this->flow = flow;
    }
};

int inc_flow(vector<set<pair<int, edge*>>> &graph) {
    int n = graph.size();
    vector<int> parents (n, -1);
    vector<vector<pair<int, edge*>>> cur_flow (n, vector<pair<int, edge*>>(n));
    queue<int> queue;
    vector<int> cur_flow_num(n, 0);
    queue.push(0);
    cur_flow_num[0] = INF;

    while ((parents[n - 1] == -1) && (!queue.empty())) {
        int current = queue.front();
        queue.pop();
        for (pair<int, edge*> e: graph[current]) {
            if ((e.second->from != e.second->to) && (parents[e.second->to] == -1) && (e.second->capacity - e.second->flow > 0)) {
                queue.push(e.second->to);
                parents[e.second->to] = current;
                cur_flow[current][e.second->to] = e;
                if (cur_flow_num[current] <= e.second->capacity - e.second->flow)
                    cur_flow_num[e.second->to] = cur_flow_num[current];
                else
                    cur_flow_num[e.second->to] = e.second->capacity - e.second->flow;
            }
        }
    }

    if (parents[n - 1] == -1)
        return 0;

    int current = n - 1;
    int min_flow = cur_flow_num[n - 1];
    while (current != 0) {
        pair<int, edge*> e = cur_flow[parents[current]][current];
        e.second->flow += min_flow;
        (e.second->inv_e)->flow -= min_flow;
        current = parents[current];
    }
    return min_flow;
}

pair<int, vector<pair<int, edge*>>> simple_decomp(int start, vector<set<pair<int, edge*>>> &graph){
    int n = graph.size();
    int t = n - 1;
    vector<pair<int, edge*>> used_edges;
    int v = start;
    int min_flow = INF;
    while (v != t){
        int to;
        if (v == t)
            break;
        pair<int, edge*> ed = make_pair(-1, new edge(-1, -1, -1, -1));
        for (pair<int, edge*> e: graph[v]) {
            if (e.second->flow > 0){
                ed = e;
                to = e.second->to;
                if (ed.second->flow < min_flow)
                    min_flow = ed.second->flow;
                break;
            }
        }
        if (ed.second->from == -1) {
            vector<pair<int, edge*>> pust;
            return make_pair(-1, pust);
        }
        used_edges.push_back(ed);
        v = to;
    }
    for (pair<int, edge*> e: used_edges) {
        e.second->flow = e.second->flow - min_flow;
        if (e.second->flow <= 0)
            graph[e.second->from].erase(e);
    }
    return make_pair(min_flow, used_edges);
}

int main() {
    freopen("decomposition.in", "r", stdin);
    freopen("decomposition.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, v1, v2, capacity;
    cin >> n >> m;
    vector<set<pair<int, edge*>>> graph (n, set<pair<int, edge*>>());
    int k = 0;
    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2 >> capacity;
        k++;
        edge* e = new edge(v1 - 1, v2 - 1, capacity, 0);
        edge* inv_e = new edge(v2 - 1, v1 - 1, 0, 0);
        e->inv_e = inv_e;
        inv_e->inv_e = e;
        graph[v1 - 1].insert(make_pair(k, e));
        graph[v2 - 1].insert(make_pair(k + m, inv_e));
    }

    while (true) {
        int add_flow = inc_flow(graph);
        if (add_flow <= 0)
            break;
    }

    vector<pair<int, vector<pair<int, edge*>>>> decompos;
    pair<int, vector<pair<int, edge*>>> path = simple_decomp(0, graph);
    while (!path.second.empty()){
        decompos.push_back(path);
        path = simple_decomp(0, graph);
    }

    cout << decompos.size() << "\n";
    for (int i = 0; i < decompos.size(); ++i) {
        cout << decompos[i].first << " " << decompos[i].second.size() << " ";
        for (pair<int, edge*> e: decompos[i].second) {
            cout << e.first << " ";
        }
        cout << "\n";
    }
    return 0;
}