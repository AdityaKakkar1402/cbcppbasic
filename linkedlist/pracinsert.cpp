#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertHead(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
    }
    else
    {
        node *n = new node(d);
        n->next = head;
        head = n;
    }
}

void printll(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    node *head = NULL;
    insertHead(head, 3);
    insertHead(head, 7);
    insertHead(head, 9);
    printll(head);
}