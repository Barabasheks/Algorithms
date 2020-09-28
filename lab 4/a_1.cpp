#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next_node
    ;
};

void push(Node** head, int value)
{
    Node* element = new Node;
    element->value = value;
    element->next_node = *head;
    *head = element;
}
void pop(Node** head)
{
    cout << (*head)->value << '\n';
    *head = (*head)->next_node;
}

int main()
{
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    Node* head = new Node;
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

