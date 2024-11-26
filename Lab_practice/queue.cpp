#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int sz = 0;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void PUSH(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    sz++;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void POP(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Queue is empty! Cannot perform POP operation." << endl;
        return;
    }
    Node *deleteNode = head;
    sz--;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    else
    {
        tail = NULL;
    }
    delete deleteNode;
}

void Display(Node *head)
{
    if (head == NULL)
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int SIZE()
{
    return sz;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int x;

    while (true)
    {
        cout << "\n1. Create a Queue using PUSH operation." << endl;
        cout << "2. Display the Queue." << endl;
        cout << "3. Insert item to the Queue using PUSH." << endl;
        cout << "4. Delete item from the Queue using POP." << endl;
        cout << "5. Find the size of the Queue." << endl;
        cout << "0. Exit the program." << endl;
        cout << "Choose your Option: ";
        int op;
        cin >> op;

        if (op == 1)
        {
            cout << "Enter the number of elements in the queue: ";
            int n;
            cin >> n;
            while (n--)
            {
                cin >> x;
                PUSH(head, tail, x);
            }
        }
        else if (op == 2)
        {
            cout << "The queue is: ";
            Display(head);
        }
        else if (op == 3)
        {
            cout << "Add item to the Queue using PUSH operation: ";
            cin >> x;
            PUSH(head, tail, x);
        }
        else if (op == 4)
        {
            cout << "using POPO operation item deleted." << endl;
            POP(head, tail);
        }
        else if (op == 5)
        {
            cout << "The size of the Queue is: " << SIZE() << endl;
        }
        else if (op == 0)
        {
            cout << "Exiting the program." << endl;
            break;
        }
        else
        {
            cout << "Invalid option! Please try again." << endl;
        }
    }
    return 0;
}
