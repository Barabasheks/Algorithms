#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int value;
    Node* next_node;
};

void push(Node** head, int value)
{
    Node* element = new Node;
    element->value = value;
    element->next_node = *head;
    *head = element;
}

void pop(Node** head, bool* flag)
{
    if((*head)->next_node == NULL) {
        *head = NULL;
    }else {
        *head = (*head)->next_node;
    }
}

int main()
{
    ifstream file("brackets.in");
    freopen("brackets.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string line;
    while (getline(file, line)) {
        Node *head = NULL;
        char bracket;
        int int_bracket = 0;
        bool flag = false;
        int i = 0;
        line += '\n';
        while(line[i] != '\n') {
            bracket = line[i];
            switch (bracket) {
                case '(':
                    int_bracket = 1;
                    break;
                case '{':
                    int_bracket = 2;
                    break;
                case '[':
                    int_bracket = 3;
                    break;
                case ')':
                    int_bracket = -1;
                    break;
                case '}':
                    int_bracket = -2;
                    break;
                case ']':
                    int_bracket = -3;
                    break;
            }
            if (int_bracket > 0) {
                push(&head, int_bracket);
            }
            if (int_bracket < 0) {
                if (head != NULL && head->value + int_bracket == 0)
                    pop(&head, &flag);
                else
                    flag = true;
                if (flag)
                    break;
            }
            i++;
        }
        if(!flag && head == NULL)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}