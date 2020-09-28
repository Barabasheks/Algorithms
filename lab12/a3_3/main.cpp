#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

const int INF = INT_MAX;

struct edge {
    int from, to, capacity, flow, num;

    edge(int from, int to, int capacity, int flow, int num){
        this->from = from;
        this->to = to;
        this->capacity = capacity;
        this->flow = flow;
        this->num = num;
    }
};

bool bfs(vector<int>& dist, vector<vector<int>>& graph, vector<edge>& edges) {
    int n = graph.size();
    int s = 0, t = n -1;
    queue<int> queue;
    queue.push(s);
    for (int i = 0; i < n; ++i)
        dist[i] = -1;
    dist[s] = 0;
    while ((!queue.empty()) && dist[t] == -1) {
        int v = queue.front();
        queue.pop();
        for (int i = 0; i < graph[v].size(); ++i) {
            int id_edge = graph[v][i], to = edges[id_edge].to;
            if (dist[to] == -1 && edges[id_edge].flow < edges[id_edge].capacity) {
                queue.push(to);
                dist[to] = dist[v] + 1;
            }
        }
    }
    return (dist[t] != -1);
}

int dfs (int v, int flow, vector<int>& dist, vector<int>& ptr, vector<vector<int>>& graph, vector<edge>& edges) {
    int n = graph.size();
    int s = 0, t = n - 1;
    if (!flow)
        return 0;
    if (v == t)
        return flow;
    while (ptr[v] < graph[v].size()) {
        int id_edge = graph[v][ptr[v]], to = edges[id_edge].to;
        if (dist[to] == dist[v] + 1) {
            int pushed = dfs(to, min(flow, edges[id_edge].capacity - edges[id_edge].flow), dist, ptr, graph, edges);
            if (pushed != 0) {
                edges[id_edge].flow += pushed;
                int id_reverse_edge = id_edge;
                if (id_reverse_edge % 2 == 0)
                    id_reverse_edge++;
                else
                    id_reverse_edge--;
                edges[id_reverse_edge].flow -= pushed;
                return pushed;
            }
        }
        ptr[v]++;
    }
    return 0;
}

pair<int, list<edge*>> simple_decomp(int start, vector<vector<edge*>> &graph){
    int n = graph.size();
    int t = n - 1;
    list<edge*> used_edges;
    vector<char> used_v (n, 0);
    int v = start;
    while (!used_v[v]){
        int to;
        if (v == t)
            break;
        edge* e = new edge(-1, -1, -1, -1, -1);
        for (int i = 0; i < graph[v].size(); ++i) {
            to = graph[v][i]->to;
            if (graph[v][i]->flow > 0){
                e = graph[v][i];
                break;
            }
        }
        if (e->from == -1)
            return make_pair(-1, list<edge*>());
        used_edges.push_back(e);
        used_v[v] = 1;
        v = to;
    }
    int min_flow = INF;
    for (edge* e: used_edges) {
        if (e->flow < min_flow)
            min_flow = e->flow;
    }
    for (edge* e: used_edges) {
        e->flow = e->flow - min_flow;
    }
    return make_pair(min_flow, used_edges);
}

int main() {
    freopen("decomposition.in", "r", stdin);
    freopen("decomposition.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, s = 0, t;
    cin >> n >> m;
    t = n - 1;

    vector<edge> edges;
    vector<vector<int>> graph(n, vector<int>());
    vector<int> dist(n);

    int v1, v2, cap, k = 0;
    for (int i = 0; i < m; ++i) {
        cin >> v1 >> v2 >> cap;
        v1 = v1 - 1;
        v2 = v2 - 1;
        edge e = edge(v1, v2, cap, 0, k);
        graph[v1].push_back (edges.size());
        edges.push_back (e);
        e = edge(v2, v1, 0, 0, -1);
        graph[v2].push_back (edges.size());
        edges.push_back (e);
        k++;
    }

    while(true) {
        if (!bfs(dist, graph, edges))
            break;
        vector<int> ptr(n, 0);
        int add_flow = dfs (s, INF, dist, ptr, graph, edges);
        while (add_flow != 0) {
            add_flow = dfs (s, INF, dist, ptr, graph, edges);
        }
    }

    vector<vector<edge*>> max_flow_graph (n, vector<edge*>());
    for (int i = 0; i < edges.size(); ++i) {
        if (edges[i].flow > 0) {
            int from = edges[i].from;
            max_flow_graph[from].push_back(&edges[i]);
        }
    }

    vector<pair<int, list<edge*>>> decompos;
    pair<int, list<edge*>> path = simple_decomp(0, max_flow_graph);
    while (!path.second.empty()){
        decompos.push_back(path);
        path = simple_decomp(0, max_flow_graph);
    }

    cout << decompos.size() << "\n";
    for (int i = 0; i < decompos.size(); ++i) {
        cout << decompos[i].first << " " << decompos[i].second.size() << " ";
        for (edge* e: decompos[i].second) {
            cout << e->num + 1 << " ";
        }
        cout << "\n";
    }
}