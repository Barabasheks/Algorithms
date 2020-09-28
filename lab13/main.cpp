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
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string str;
    cin >> str;
    vector <int> pi = prefix_function(str);
    for (int i = 0; i < pi.size(); ++i) {
        cout << pi[i] << " ";
    }
    return 0;
}
