#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph;
    vector<char> input;
    vector<bool> used;
    vector<string> way;
    char node;
    for (int i = 0; i < n * m; ++i) {
        cin >> node;
        input.push_back(node);
        graph.push_back(vector<int>());
        used.push_back(false);
        way.push_back("");
    }
    int begin, end;
    for (int j = 0; j < n * m; ++j) {
        node = input[j];
        if (node != '#' ){
            if ((j - m >= 0) && (input[j - m] != '#'))
                graph[j].push_back(j - m);
            if ((j + m < n * m) && (input[j + m] != '#'))
                graph[j].push_back(j + m);
            if ((j - 1 >= 0) && ((j - 1) / m == j / m) && (input[j - 1] != '#'))
                graph[j].push_back(j - 1);
            if ((j + 1 < n * m) && ((j + 1) / m == j / m) && (input[j + 1] != '#'))
                graph[j].push_back(j + 1);
        }
        if (node == 'S')
            begin = j;
        if (node == 'T')
            end = j;
    }
    queue<int> queue;
    queue.push(begin);
    used[begin] = true;
    bool flag = true;
    while (!queue.empty() && flag){
        int this_node = queue.front();
        queue.pop();
        for (int i = 0; i < graph[this_node].size(); ++i) {
            int to = graph[this_node][i];
            if(!used[to]) {
                queue.push(to);
                used[to] = true;
                if (this_node - to == m)
                    way[to] = way[this_node] + "U";
                else if (this_node - to == -m)
                    way[to] = way[this_node] + "D";
                else if (this_node - to == 1)
                    way[to] = way[this_node] + "L";
                else if (this_node - to == -1)
                    way[to] = way[this_node] + "R";
                if (to == end)
                    flag = false;
            }
        }
    }
    if(way[end].length() == 0){
        cout << -1;
    } else{
        cout << way[end].length() << "\n";
        cout << way[end];
    }
    return 0;
}
