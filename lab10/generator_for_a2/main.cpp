#include <iostream>
#include <stdlib.h> // srand, rand
#include <time.h>   // time
using namespace std;

int main() {
    freopen("spantree.in", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    srand(time(0));
    int n = 1 + rand() % 7500;
    cout << n << endl;

    for (int i = 0; i < n; ++i) {
        int x = -10000 + rand() % 20000;
        int y = -10000 + rand() % 20000;
        cout << x << " " << y << endl;
    }
    return 0;
}
