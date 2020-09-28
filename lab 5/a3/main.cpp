#include <iostream>

using namespace std;

struct Node {
    string* value;
    string* key;
    Node *next_node;
    Node *prev_elem;
    Node *next_elem;
};

int hash_func(string key) {
    int sum = 0;
    for(int i = 0; i < key.length(); i++){
        sum += (key[i] - 'a') * (i + 1);
    }
    return abs(sum % 100000);
}

Node* add(string value, string key, Node **current_node, Node** last_elem) {
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
        new_node->next_elem = nullptr;
        *(new_node->key) = key;
        *(new_node->value) = value;
        new_node->prev_elem = *last_elem;
        if(*last_elem != nullptr)
            (*last_elem)->next_elem = new_node;
        return new_node;
    }else{
        *(cur_node->value) = value;
        return *last_elem;
    }
}

void del(string key, Node** current_node, Node** last_elem){
    Node* cur_node = *current_node;
    Node* last_node = cur_node;
    while(cur_node != nullptr){
        if(cur_node->key != nullptr && *(cur_node->key) == key){
            if(cur_node == *last_elem && *last_elem != nullptr)
                *last_elem = (*last_elem)->prev_elem;
            if(cur_node->prev_elem != nullptr)
                (cur_node->prev_elem)->next_elem = cur_node->next_elem;
            if(cur_node->next_elem != nullptr)
                (cur_node->next_elem)->prev_elem = cur_node->prev_elem;
            last_node->next_node = cur_node->next_node;
            delete(cur_node);
            return;
        }
        last_node = cur_node;
        cur_node = cur_node->next_node;
    }
}

string exists(string key, Node** current_node){
    Node* cur_node = *current_node;
    while(cur_node != nullptr){
        if(cur_node->key != nullptr && *(cur_node->key) == key){
            return  *(cur_node->value);
        }
        cur_node = cur_node->next_node;
    }
    return "none";
}

Node* find(string key, Node** current_node){
    Node* cur_node = *current_node;
    while(cur_node != nullptr){
        if(cur_node->key != nullptr && *(cur_node->key) == key){
            return  cur_node;
        }
        cur_node = cur_node->next_node;
    }
    return nullptr;
}


int main() {
    Node *hash_table[100000];
    Node *last_elem = nullptr;
    for (int i = 0; i < 100000; i++) {
        hash_table[i] = new Node;
        hash_table[i]->value = nullptr;
        hash_table[i]->key = nullptr;
        hash_table[i]->next_node = nullptr;
        hash_table[i]->next_elem = nullptr;
        hash_table[i]->prev_elem = nullptr;
    }
    string command, value, key;
    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while (cin >> command) {
        cin >> key;
        if (command == "put") {
            cin >> value;
            last_elem = add(value, key, &hash_table[hash_func(key)], &last_elem);
        }
        if (command == "delete"){
            del(key, &hash_table[hash_func(key)], &last_elem);
        }
        if(command == "get"){
            cout<< exists(key, &hash_table[hash_func(key)]) << "\n";
        }
        if(command == "prev"){
            Node* cur_node = find(key, &hash_table[hash_func(key)]);
            if (cur_node != nullptr && cur_node->prev_elem != nullptr){
                cout << *((cur_node->prev_elem)->value) << "\n";
            } else{
                cout << "none\n";
            }
        }
        if(command == "next"){
            Node* cur_node = find(key, &hash_table[hash_func(key)]);
            if (cur_node != nullptr && cur_node->next_elem != nullptr){
                cout << *((cur_node->next_elem)->value) << "\n";
            } else{
                cout << "none\n";
            }
        }
    }
}