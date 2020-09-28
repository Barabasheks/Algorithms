#include <iostream>
#include <vector>

using namespace std;

bool equal(vector<int> vector1, vector<int> vector2){
    if (vector1.size() == vector2.size()) {
        for (int i = 0; i < vector1.size(); ++i) {
            if (vector1[i] != vector2[i])
                return false;
        }
    } else{
        return false;
    }
    return true;
}

int main() {
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, ver1, ver2;
    cin >> n >> m;
    vector<vector<int>> graph (n, vector<int>());
    for (int i = 0; i < m; ++i) {
        cin >> ver1 >> ver2;
        graph[ver1 - 1].push_back(ver2 - 1);
        graph[ver2 - 1].push_back(ver1 - 1);
    }

    vector<int> part (n, -1);
    bool bipartite = true;
    vector<int> query (n);
    for (int i = 0; i < n; ++i)
        if (part[i] == -1) {
            int t = 0;
            query[t++] = i;
            part[i] = 0;
            for (int j = 0; j < t; ++j) {
                int v = query[j];
                for (int k = 0; k < graph[v].size(); ++k) {
                    int to = graph[v][k];
                    if (part[to] == -1) {
                        part[to] = !part[v];
                        query[t++] = to;
                    }
                    else
                        bipartite &= part[to] != part[v];
                }
            }
        }

    cout << (bipartite ? "YES" : "NO");
    return 0;
}
