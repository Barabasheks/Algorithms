#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string str, form;
    cin >> form >> str;
    vector<int> start_indexes;
    for (int i = 0; i < str.length() - form.length() + 1; ++i) {
        bool flag = true;
        for (int j = 0; j < form.length(); ++j) {
            if (str[i + j] != form[j]){
                flag = false;
                break;
            }
        }
        if (flag)
            start_indexes.push_back(i + 1);
    }

    cout << start_indexes.size() << endl;
    for (int start_indexe : start_indexes) {
        cout << start_indexe << " ";
    }
    return 0;
}
