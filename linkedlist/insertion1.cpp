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
        while (jump < p - 1)
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

void deleteHead(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head->next;
    delete head;
    head = temp;
}
// void deleteAtTail(node *&head)
// {
//     if (head == NULL)
//     {
//         return;
//     }
//     else if (head->next == NULL)
//     {
//         deleteHead(head);
//         return;
//     }

//     else
//     {
//         node *temp = head;
//         while (temp->next->next != NULL)
//         {
//             temp = temp->next;
//         }
//         node *tobedeleted = temp->next;
//         temp->next = NULL;
//         delete tobedeleted;
//     }
// }
void deleteAtTail(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        deleteHead(head);
        return;
    }

    else
    {
        node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = NULL;
        temp = temp->next;
        delete temp;
    }
}

void deletePosition(node *&head, int p)
{
    if (head == NULL || head->next == NULL || p <= 1)
    {
        return;
    }

    else if (p >= length(head))
    {
        deleteAtTail(head);
    }

    else
    {
        int jump = 1;
        node *temp = head;
        while (jump < p - 1)
        {
            temp = temp->next;
            jump++;
        }
        node *tobedeleted = temp->next;
        temp->next = temp->next->next;
        delete tobedeleted;
    }
}

//only linear search can be implemented in linked list
//as it will be more feasible. Doing binary search
//will take more time than usual
//and we cannot directly access ith term.

//linear search
bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
//recursively search
bool searchRecursive(node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }
    //rec case check at head,remaining linked list
    if (head->data == key)
    {
        return true;
    }
    else
    {
        return searchRecursive(head->next, key);
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
    insertATHead(head, 4);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    insertInMiddle(head, 3, 2);
    insertATHead(head, 2);

    insertATHead(head, 1);

    insertATHead(head, 0);
    insertInMiddle(head, 3, 3);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    deleteHead(head);
    deleteHead(head);
    deleteAtTail(head);
    deletePosition(head, 3);

    printNode(head);
    int key;

    cin >> key;
    cin >> key;
    if (searchRecursive(head, key))
    {
        cout << "found";
    }
    else
    {
        cout << "not found";
    }
    if (search(head, key))
    {
        cout << "found";
    }
    else
    {
        cout << "not found";
    }
}