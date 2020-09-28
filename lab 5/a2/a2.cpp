#include <iostream>

using namespace std;

struct Node {
    string* value;
    string* key;
    Node *next_node;
};

int hash_func(string key) {
    int sum = 0;
    for(int i = 0; i < key.length(); i++){
        sum += (key[i] - 'a') * (i + 1);
    }
    return abs(sum % 500000);
}

void add(string value, string key, Node **current_node) {
    bool flag = false;
    Node* cur_node = *current_node;
    Node* last_node = cur_node;
    while (cur_node != nullptr) {
        if (cur_node->key != nullptr && *(cur_node->key) == key) {
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
        new_node->value = new string;
        new_node->key = new string;
        *(new_node->key) = key;
        *(new_node->value) = value;
    }else{
        *(cur_node->value) = value;
    }
}

void del(string key, Node** current_node){
    Node* cur_node = *current_node;
    if(cur_node->key != nullptr && *(cur_node->key) == key){
        *cur_node = *cur_node->next_node;
    }else{
        Node* last_node = cur_node;
        while(cur_node != nullptr){
            if(cur_node->key != nullptr && *(cur_node->key) == key){
                last_node->next_node = cur_node->next_node;
                break;
            }
            last_node = cur_node;
            cur_node = cur_node->next_node;
        }
    }
}

void exists(string key, Node** current_node){
    Node* cur_node = *current_node;
    bool flag = false;
    while(cur_node != nullptr){
        if(cur_node->key != nullptr && *(cur_node->key) == key){
            cout << *(cur_node->value) << "\n";
            flag = true;
            break;
        }
        cur_node = cur_node->next_node;
    }
    if (!flag){
        cout << "none\n";
    }
}

int main() {
    Node *hash_table[500000];
    for (int i = 0; i < 500000; i++) {
        hash_table[i] = new Node;
        hash_table[i]->value = nullptr;
        hash_table[i]->key = nullptr;
        hash_table[i]->next_node = nullptr;
    }
    string command, value, key;
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while (cin >> command) {
        cin >> key;
        if (command == "put") {
            cin >> value;
            add(value, key, &hash_table[hash_func(key)]);
        }
        if (command == "delete"){
            del(key, &hash_table[hash_func(key)]);
        }
        if(command == "get"){
            exists(key, &hash_table[hash_func(key)]);
        }
    }
}