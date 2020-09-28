#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = INT_MAX;

class edge{
public:
    int from, to, capMax, capMin, flow, num, flow_change;
    edge* inv_e;
    
    edge(int from, int to, int capMin, int capMax, int num){
        this->from = from;
        this->to = to;
        this->capMin = capMin;
        this->capMax = capMax;
        this->flow = 0;
        this->num = num;
        this->flow_change = this->capMin;
    }
};

int inc_flow(vector<vector<edge*>> &graph) {
    int n = graph.size();
    vector<int> parents (n, -1);
    vector<vector<edge*>> cur_flow (n, vector<edge*>(n));
    queue<int> queue;
    queue.push(0);

    while ((parents[n - 1] == -1) && (!queue.empty())) {
        int current = queue.front();
        queue.pop();
        for (edge* e: graph[current]) {
            if ((e->from != e->to) && (parents[e->to] == -1) && (e->capMax - e->flow > 0)) {
                queue.push(e->to);
                parents[e->to] = current;
                cur_flow[current][e->to] = e;
            }
        }
    }

    if (parents[n - 1] == -1)
        return 0;

    int current = n - 1;
    int min_flow = INF;
    while (current != 0) {
        edge* e = cur_flow[parents[current]][current];
        if (e->capMax - e->flow < min_flow)
            min_flow = e->capMax - e->flow;
        current = parents[current];
    }
    current = n - 1;
    while (current != 0) {
        edge* e = cur_flow[parents[current]][current];
        e->flow += min_flow;
        e->inv_e->flow -= min_flow;
        current = parents[current];
    }
    return min_flow;
}

int main() {
    freopen("circulation.in", "r", stdin);
    freopen("circulation.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, k = 0;
    cin >> n >> m;
    vector<vector<edge*>> graph (n + 2, vector<edge*>());
    int v1, v2, capMin, capMax;
    for (int i = 0; i < m; ++i) {
        k++;
        cin >> v1 >> v2 >> capMin >> capMax;
        graph[v1].push_back(new edge(v1, v2, capMin, capMax, k));
    }
    for (int i = 1; i < n + 1; ++i) {
        int size = graph[i].size();
        for (int j = 0; j < size; j++) {
            edge* e = graph[i][j];
            graph[0].push_back(new edge(0, e->to, 0, e->capMin, 0));
            graph[e->from].push_back(new edge(e->from, n + 1, 0, e->capMin, -1));
            e->capMax = e->capMax - e->capMin;
            e->capMin = 0;
        }
    }

    for (int i = 0; i < n + 2; ++i) {
        for (edge* e: graph[i]) {
            edge* inv_e = new edge(e->to, e->from, 0, 0, -1);
            e->inv_e = inv_e;
            inv_e->inv_e = e;
        }
    }

    int add_flow = 0;
    while (true){
        add_flow = inc_flow(graph);
        if (add_flow == 0)
            break;
    }

    bool circulation = true;
    for (edge* e: graph[0]) {
        if (e->flow < e->capMax)
            circulation = false;
    }
    vector<int> flow (m + 1);
    if (circulation){
        cout << "YES\n";
        for (int i = 1; i < n + 1; ++i) {
            for (edge* e: graph[i]) {
                if (e->num > 0)
                    flow[e->num] = e->flow + e->flow_change;
            }
        }
        for (int i = 1; i < m + 1; ++i) {
            cout << flow[i] << "\n";
        }
    } else
        cout << "NO";

    return 0;
}
