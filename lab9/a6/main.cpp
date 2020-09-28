#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, int player, vector<vector<int>> &graph, vector<vector<int>> &tr_graph, vector<char> &used)
{
    if (graph[v].empty())
    {
        used[v] = -1;
        for (int i : tr_graph[v])
            used[i] = 1;
        return;
    }
    for (int i = 0; i < graph[v].size(); i++)
        if (used[graph[v][i]] == 0)
        {
            dfs(graph[v][i], -player, graph, tr_graph, used);
            for (int j = 0; j < tr_graph[graph[v][i]].size(); j++) {
                int up_v = tr_graph[graph[v][i]][j];
                if (used[up_v] != 1)
                    used[up_v] = -used[graph[v][i]];
            }
        }
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, s;
    cin >> n >> m >> s;
    vector <vector<int>> graph (n, vector<int>()), tr_graph(n, vector<int>());
    vector<char> used(n, 0);
    for (int i = 0; i < m; i++)
    {
        int ver1, ver2;
        cin >> ver2 >> ver1;
        graph[ver2 - 1].push_back(ver1 - 1);
        tr_graph[ver1 - 1].push_back(ver2 - 1);
    }
    dfs(s - 1, 1, graph, tr_graph, used);

    if(used[s - 1] == 1)
        cout << "First player wins";
    else
        cout << "Second player wins";

    return 0;
}