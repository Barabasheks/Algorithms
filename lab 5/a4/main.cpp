#include <iostream>

using namespace std;

struct Node {
    string* value;
    string* key;
    Node *next_node;
    Node *end_node;
};

int hash_func(string key) {
    int sum = 0;
    for(int i = 0; i < key.length(); i++){
        sum += (key[i] - 'a') * (i + 1);
    }
    return abs(sum % 500);
}

void add(string value, string key, Node **current_node) {
    bool flag = false;
    Node* cur_node = *current_node;
    Node* last_node = cur_node;
    while (cur_node != nullptr) {
        if (cur_node->key != nullptr && *(cur_node->key) == key && cur_node->end_node == nullptr){

        }
        if (cur_node->key != nullptr && *(cur_node->key) == key && *(cur_node->value) == value) {
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
    }
}

void del(string key, string value,  Node** current_node){
    Node* cur_node = *current_node;
    if(cur_node->key != nullptr && *(cur_node->key) == key && *(cur_node->value) == value){
        *cur_node = *cur_node->next_node;
    }else{
        Node* last_node = cur_node;
        while(cur_node != nullptr){
            if(cur_node->key != nullptr && *(cur_node->key) == key && *(cur_node->value) == value){
                last_node->next_node = cur_node->next_node;
                break;
            }
            last_node = cur_node;
            cur_node = cur_node->next_node;
        }
    }
}

void delall(string key,  Node** current_node){
    for(int i = 0; i < 500; i++){
        Node* cur_node = current_node[i];
        Node* last_node = cur_node;
        while(cur_node != nullptr){
            if(cur_node->key != nullptr && *(cur_node->key) == key){
                last_node->next_node = cur_node->next_node;
                cur_node = last_node;
                continue;
            }
            last_node = cur_node;
            cur_node = cur_node->next_node;
        }
    }
}

void exists(string key, Node** current_node){
    int num = 0;
    string values = "";
    for (int i = 0; i < 500; i++) {
        Node* cur_node = current_node[i];
        while(cur_node != nullptr){
            if(cur_node->key != nullptr && *(cur_node->key) == key){
                num ++;
                values += *(cur_node->value) + " ";
            }
            cur_node = cur_node->next_node;
        }
    }
    cout << num << " " << values;
    cout << "\n";
}

int main() {
    Node *hash_table[500][500];
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 500; j++) {
            hash_table[i][j] = new Node;
            hash_table[i][j]->value = nullptr;
            hash_table[i][j]->key = nullptr;
            hash_table[i][j]->next_node = nullptr;
            hash_table[i][j]->end_node = nullptr;
        }
    }
    string command, value, key;
    freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while (cin >> command) {
        cin >> key;
        if (command == "put") {
            cin >> value;
            add(value, key, &hash_table[hash_func(key)][hash_func(value)]);
        }
        if (command == "delete"){
            cin >> value;
            del(key, value, &hash_table[hash_func(key)][hash_func(value)]);
        }
        if(command == "deleteall"){
            delall(key, &hash_table[hash_func(key)][0]);
        }
        if(command == "get"){
            exists(key, &hash_table[hash_func(key)][0]);
        }
    }
}