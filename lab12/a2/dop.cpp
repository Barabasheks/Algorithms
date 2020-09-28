//#include <iostream>
//#include <vector>
//using namespace std;
//
//int dfs (int v, vector <vector<int>>& graph, vector<int>& matching, vector<char>& used) {
//    used[v] = true;
//    for (int i = 0; i < graph[v].size(); ++i) {
//        int to = graph[v][i];
//        bool b_dfs = false;
//        if (matching[to] >= 0 && used[matching[to]])
//            b_dfs = dfs(matching[to], graph, matching, used);
//        if (matching[to] == -1 || b_dfs) {
//            matching[to] = v;
//            return 1;
//        }
//    }
//    return 1;
//}
//
//int main() {
//    freopen("matching.in", "r", stdin);
//    freopen("matching.out", "w", stdout);
//    ios_base::sync_with_stdio(false); cin.tie(NULL);
//
//    int n1, n2, m;
//    cin >> n1 >> n2 >> m;
//    vector <vector<int>> graph (n1, vector<int>());
//    vector<int> matching(n2, -1);
//
//    int ver1, ver2;
//    for (int i = 0; i < m; ++i) {
//        cin >> ver1 >> ver2;
//        graph[ver1 - 1].push_back(ver2 - 1);
//    }
//
//    int num_of_matching = 0;
//    int num_of_matching2 = 0;
//    for (int i = 0; i < n1; ++i) {
//        vector<char> used(n1, 0);
//        num_of_matching += dfs(i, graph, matching, used);
//    }
//    for (int i = 0; i < n2; ++i) {
//        if (matching[i] != -1){
//            num_of_matching2++;
//        }
//    }
//    cout << num_of_matching << " " << num_of_matching2;
//}