#include <iostream>
#include <vector>

using namespace std;

string check_tree(int (*list_of_nodes)[3], int index, int prev_key, string child){
    string check_left, check_right;
    if (child == "left"){
        if(list_of_nodes[index][0] < prev_key){
            if (list_of_nodes[index][1] != 0) {
                check_left = check_tree(list_of_nodes, list_of_nodes[index][1] - 1, list_of_nodes[index][0], "left");
            }else{
                return "YES";
            }
            if (list_of_nodes[index][2] != 0) {
                check_right = check_tree(list_of_nodes, list_of_nodes[index][2] - 1, list_of_nodes[index][0], "right");
            }else{
                return "YES";
            }
        } else{
            return "NO";
        }
    } else if (child == "right"){
        if(list_of_nodes[index][0] > prev_key){
            if (list_of_nodes[index][1] != 0) {
                check_left = check_tree(list_of_nodes, list_of_nodes[index][1] - 1, list_of_nodes[index][0], "left");
            }else{
                return "YES";
            }
            if (list_of_nodes[index][2] != 0) {
                check_right = check_tree(list_of_nodes, list_of_nodes[index][2] - 1, list_of_nodes[index][0], "right");
            }else{
                return "YES";
            }
        } else{
            return "NO";
        }
    } else{
        return "NO";
    }
    if (check_left == "YES" && check_right == "YES")
        return "YES";
    else
        return "NO";
}

int main() {
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int list_of_nodes[n][3];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j){
            cin >> list_of_nodes[i][j];
        }
    }
    if (list_of_nodes[0][1] != 0 || list_of_nodes[0][2] != 0) {
        if (list_of_nodes[0][1] != 0 && list_of_nodes[0][2] == 0) {
            cout << check_tree(list_of_nodes, list_of_nodes[0][1] - 1, list_of_nodes[0][0], "left");
        }
        else if (list_of_nodes[0][1] == 0 && list_of_nodes[0][2] != 0) {
            cout << check_tree(list_of_nodes, list_of_nodes[0][2] - 1, list_of_nodes[0][0], "right");
        }
        else if (check_tree(list_of_nodes, list_of_nodes[0][1] - 1, list_of_nodes[0][0], "left") == "YES"
            && check_tree(list_of_nodes, list_of_nodes[0][2] - 1, list_of_nodes[0][0], "right") == "YES")
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "YES";
}