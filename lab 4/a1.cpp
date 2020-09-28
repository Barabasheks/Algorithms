#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next_node;
    Node* previous_node;
};

void push(Node** head, int value)
{
    Node* element = new Node;
    element->value = value;
    element->next_node = *head;
    (*head)->previous_node = element;
    *head = element;
}

void pop(Node** last)
{
    cout << (*last)->value << '\n';
    Node* del_el = *last;
    *last = (*last)->previous_node;
    delete(del_el);
}

int main()
{
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    Node* head = new Node;
    Node* last = head;
    int n;
    cin >> n;
    char command;
    cin >> command;
    int value;
    cin >> value;
    head->value = value;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> command;
        if(command == '+')
        {
            cin >> value;
            push(&head, value);
        }
        if(command == '-')
        {
            pop(&head);
        }
    }
}
