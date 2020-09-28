#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* previous_node;
};

void push(Node** head, int value)
{
    if(*head != NULL) {
        Node *element = new Node;
        element->value = value;
        (*head)->previous_node = element;
        *head = element;
    }
    else {
        Node *element = new Node;
        element->value = value;
        *head = element;
    }
}

void pop(Node** last, Node** head)
{
    cout << (*last)->value << '\n';
    if(*last != *head) {
        *last = (*last)->previous_node;
    }
    else {
        *last = NULL;
        *head = NULL;
    }
}

int main()
{
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    Node* head = NULL;
    Node* last = NULL;
    int n;
    cin >> n;
    char command;
    int value;
    for(int i = 0; i < n; i++)
    {
        cin >> command;
        if(command == '+')
        {
            cin >> value;
            push(&head, value);
            if(last == NULL)
                last = head;
        }
        if(command == '-')
        {
            pop(&last, &head);
        }
    }
}
