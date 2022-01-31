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
//pass by reference has to done because if it will be
//pass by value while changing
//head in the fuction it will not change head in main
void insertATHead(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
        //dynamic allocation is done, it is because we
        //want to save changes in memory or else if static
        //memory allocation is done when next time function
        //will be called previous change will be deleted
    }
    else
    {
        node *n = new node(d);
        n->next = head;
        head = n;
    }
}

void printNode(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}

int main()
{
    node *head = NULL;
    insertATHead(head, 3);
    insertATHead(head, 2);

    insertATHead(head, 1);

    insertATHead(head, 0);
    printNode(head);
}