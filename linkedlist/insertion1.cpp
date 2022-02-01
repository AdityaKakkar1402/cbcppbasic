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

int length(node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
//(*n).next=head;
//n->next=head;

void insertInMiddle(node *&head, int d, int p)
{
    if (p == 0 || head == NULL)
    {
        insertATHead(head, d);
        return;
    }
    else if (p == length(head))
    {
        insertATHead(head, d);
    }
    else
    {
        int jump = 1;
        node *temp = head;
        while (jump <= p - 1)
        {
            temp = temp->next;
            jump++;
        }
        node *n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

void insertAtTail(node *&head, int d)
{
    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(d);
    return;
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
    insertATHead(head, 4);
    insertAtTail(head, 8);
    insertInMiddle(head, 3, 2);

    insertATHead(head, 2);

    insertATHead(head, 1);

    insertATHead(head, 0);
    insertInMiddle(head, 3, 3);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    printNode(head);
}