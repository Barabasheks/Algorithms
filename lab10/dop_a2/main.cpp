#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double distance(pair<int , int> point1, pair<int, int> point2){
    return sqrt((point1.first - point2.first)*(point1.first - point2.first) + (point1.second - point2.second)*(point1.second - point2.second));
}

int main() {
    freopen("spantree.in", "r", stdin);
    freopen("spantree.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> graph;
    vector<double> min_distance(n);
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        graph.push_back(pair<int, int>(x,y));
    }


    vector <vector<double>> g;
    for (int i = 0; i < n; ++i) {
        g.push_back(vector<double>());
        for (int j = 0; j < n; ++j) {
            g[i].push_back(distance(graph[i], graph[j]));
        }
    }
    const int INF = 1000000000; // значение "бесконечность"

// алгоритм
    double sum_way = 0;
    vector<bool> used (n);
    vector<double> min_e (n, INF), sel_e (n, -1);
    min_e[0] = 0;
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                v = j;
        if (min_e[v] == INF) {
            exit(0);
        }

        used[v] = true;
        if (sel_e[v] != -1) {
            sum_way += min_e[v];
        }
        for (int to=0; to<n; ++to)
            if (g[v][to] < min_e[to]) {
                min_e[to] = g[v][to];
                sel_e[to] = v;
            }
    }
    cout << sum_way;

    return 0;
}
