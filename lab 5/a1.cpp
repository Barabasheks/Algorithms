#include <iostream>

using namespace std;

struct Node {
    int* value;
    Node *next_node;
};

int hash_func(int value) {
    return abs(value % 500000);
}

void add(int value, Node **current_node) {
    bool flag = false;
    Node* cur_node = *current_node;
    Node* last_node = cur_node;
    while (cur_node != nullptr) {
        if (cur_node->value != nullptr && *(cur_node->value) == value) {
            flag = true;
            break;
        }
        last_node = cur_node;
        cur_node = cur_node->next_node;
    }
    if (!flag){
        Node *new_node = new Node;
        last_node->next_node = new_node;
        new_node->next_node = nullptr;
        new_node->value = new int;
        *(new_node->value) = value;
    }
}

void del(int value, Node** current_node){
    Node* cur_node = *current_node;
    if(cur_node->value != nullptr && *(cur_node->value) == value){
        *cur_node = *cur_node->next_node;
    }else{
        Node* last_node = cur_node;
        while(cur_node != nullptr){
            if(cur_node->value != nullptr && *(cur_node->value) == value){
                last_node->next_node = cur_node->next_node;
                break;
            }
            last_node = cur_node;
            cur_node = cur_node->next_node;
        }
    }
}

void exists(int value, Node** current_node){
    Node* cur_node = *current_node;
    bool flag = false;
    while(cur_node != nullptr){
        if(cur_node->value != nullptr && *(cur_node->value) == value){
            cout << "true\n";
            flag = true;
            break;
        }
        cur_node = cur_node->next_node;
    }
    if (!flag){
        cout << "false\n";
    }
}

int main() {
    Node *hash_table[500000];
    for (int i = 0; i < 500000; i++) {
        hash_table[i] = new Node;
        hash_table[i]->value = nullptr;
        hash_table[i]->next_node = nullptr;
    }
    string command;
    int value;
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while (cin >> command) {
        cin >> value;
        if (command == "insert") {
            add(value, &hash_table[hash_func(value)]);
        }
        if (command == "delete"){
            del(value, &hash_table[hash_func(value)]);
        }
        if(command == "exists"){
            exists(value, &hash_table[hash_func(value)]);
        }
    }
}