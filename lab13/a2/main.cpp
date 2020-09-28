#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function (string str) {
    vector<int> pi (str.length(), 0);
    for (int i = 1; i < str.length(); ++i) {
        int j = pi[i - 1];
        while (j > 0 && str[i] != str[j]) {
            j = pi[j - 1];
        }
        if (str[i] == str[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

int main() {
    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string str, form;
    cin >> form >> str;
    str = form + '#' + str;
    vector<int> pi = prefix_function(str);
    vector<int> start_indexes;
    for (int i = 2 * form.length(); i < pi.size(); ++i) {
        if (pi[i] == form.length())
            start_indexes.push_back(i - 2 * form.length() + 1);
    }

    cout << start_indexes.size() << endl;
    for (int j = 0; j < start_indexes.size(); ++j) {
        cout << start_indexes[j] << " ";
    }
    return 0;
}
