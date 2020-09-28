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

int pop(Node** head)
{
    int del_el = (*head)->value;
    *head = (*head)->next_node;
    return del_el;
}

int main()
{
    ifstream file("postfix.in");
    freopen("postfix.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    Node* head = NULL;
    string line;
    getline(file, line);
    int i = 0;
    while(i < line.length())
    {
        int a, b;
        switch (line[i])
        {
            case '+':
                a = pop(&head);
                b = pop(&head);
                push(&head, a + b);
                break;
            case '-':
                a = pop(&head);
                b = pop(&head);
                push(&head, b - a);
                break;
            case '*':
                a = pop(&head);
                b = pop(&head);
                push(&head, a * b);
                break;
            case ' ':
                break;
            default:
                push(&head, line[i] - '0');
                break;
        }
        ++i;
    }
    cout << head->value;
}