#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int inc_flow(vector<vector<long long>> &graph, vector<vector<long long>> &flows) {
    const long long INF = LONG_LONG_MAX;
    int n = graph.size();
    vector<int> parents (n, -1);
    vector<long long> cur_flow(n, 0);
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

    int current = n - 1;
    while (current != 0) {
        flows[parents[current]][current] += cur_flow[n - 1];
        flows[current][parents[current]] -= cur_flow[n - 1];
        current = parents[current];
    }
    return cur_flow[n - 1];
}

int main()
{
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<long long>> graph(n, vector<long long>(n, 0));
    vector<vector<long long>> flows(n, vector<long long>(n, 0));
    int ver1, ver2, capacity;
    for (int i = 0; i < m; i++) {
        cin >> ver1 >> ver2 >> capacity;
        graph[ver1 - 1][ver2 - 1] += capacity;
    }

    long long max_flow = 0;
    while (true) {
        int add_flow = inc_flow(graph, flows);
        if (add_flow <= 0)
            break;
        max_flow += add_flow;
    }
    cout << max_flow;
    return 0;
}