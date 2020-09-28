#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main() {
    int heap[1000000];
    ifstream file("priorityqueue.in");
    freopen("priorityqueue.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string command;
    getline(file, command);
    cout << command;
    //while(getline(file, command)){
    //    cout << "wdacfa \n";
    //}
}