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
    string str;
    int alphabet;
    cin >> alphabet >> str;
    int str_len = str.length() + 1;
    vector<int> pi = prefix_function (str);
    vector <vector<int>> automatic (str_len, vector<int> (alphabet));
    for (int i = 0; i < str_len; ++i)
        for (char elem_alpabet = 'a'; elem_alpabet < alphabet + 'a'; ++elem_alpabet)
            if (i != 0 && elem_alpabet != str[i])
                automatic[i][elem_alpabet - 'a'] = automatic[pi[i - 1]][elem_alpabet - 'a'];
            else
                automatic[i][elem_alpabet - 'a'] = i + (elem_alpabet == str[i]);

    for (int i = 0; i < automatic.size(); ++i) {
        for (int j = 0; j < automatic[i].size(); ++j) {
            cout << automatic[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
