#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("negcycle.in", "r", stdin);
    freopen("negcycle.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    const long long INF = 1000000000;
    int n;
    cin >> n;
    vector<vector<long long>> graph (n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    vector<long long> dist (n);
    vector<int> parent (n, -1);
    int v;
    for (int i = 0; i < n; ++i) {
        v = -1;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (dist[k] > dist[j] + graph[j][k]) {
                    dist[k] = max(-INF, dist[j] + graph[j][k]);
                    parent[k] = j;
                    v = k;
                }
            }
        }
    }

    if (v == -1) {
        cout << "NO";
    }
    else {
        for (int i = 0; i < n; ++i)
            v = parent[v];

        vector<int> path;
        int cur_v = v;
        while(cur_v != v || path.size() <= 1){
            path.push_back (cur_v);
            cur_v = parent[cur_v];
        }
        path.push_back (cur_v);
        cout << "YES\n";
        cout << path.size() << endl;
        for (int i = path.size() - 1; i >= 0; --i)
            cout << path[i] + 1 << ' ';
    }
    return 0;
}
