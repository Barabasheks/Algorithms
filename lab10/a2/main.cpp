#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double distance(pair<int , int> point1, pair<int, int> point2){
    return sqrt(pow((point1.first - point2.first), 2) + pow((point1.second - point2.second), 2));
}

int main() {
    freopen("spantree.in", "r", stdin);
    freopen("spantree.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout.precision(20);

    int n;
    cin >> n;
    vector<pair<int, int>> graph;
    vector<double> min_distance(n);
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        graph.push_back(pair<int, int>(x,y));
        min_distance[i] = distance(graph[0], graph[i]);
    }
    min_distance[0] = 1000000;

    double sum_dist = 0;
    int key_min_dis = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            if (min_distance[key_min_dis] > min_distance[j]){
                key_min_dis = j;
            }
        }
        sum_dist += min_distance[key_min_dis];
        min_distance[key_min_dis] = 1000000;
        for (int j = 0; j < n; ++j) {
            if (min_distance[j] != 1000000 && distance(graph[key_min_dis], graph[j]) < min_distance[j]){
                    min_distance[j] = distance(graph[key_min_dis], graph[j]);
            }
        }
    }
    cout << sum_dist;
    return 0;
}
