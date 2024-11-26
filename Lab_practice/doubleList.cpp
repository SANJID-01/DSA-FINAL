#include <bits/stdc++.h>
#define ll long long int
using namespace std;

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

void insert_at_Tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
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

void insert_at_Head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_at_any_position(Node *&head, Node *&tail, int index, int val)
{
    if (index == 0)
    {
        insert_at_Head(head, tail, val);
        return;
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        if (temp == NULL)
        {
            cout << "Index out of range" << endl;
            delete newNode;
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Index out of range" << endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    else
    {
        tail = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void Head_Delete(Node *&head, Node *&tail)
{
    if (head == NULL)
        return;
    Node *deleteNode = head;
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

void Delete_any_item(Node *&head, Node *&tail, int ind)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (ind == 0)
    {
        Head_Delete(head, tail);
        return;
    }
    Node *temp = head;
    for (int i = 0; i < ind; i++)
    {
        if (temp == NULL)
        {
            cout << "Index out of range" << endl;
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Index out of range" << endl;
        return;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    else
    {
        tail = temp->prev;
    }
    delete temp;
}

void Short_List(Node *head)
{
    for (Node *i = head; i != NULL && i->next != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (i->val > j->val)
            {
                int temp = i->val;
                i->val = j->val;
                j->val = temp;
            }
        }
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_reverse(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int x;
    while (true)
    {
        cout << "1. Create a Linked list . " << endl;
        cout << "2. Display the Linked list . " << endl;
        cout << "3. Reverse the Linked list . " << endl;
        cout << "4. Insert item at Head . " << endl;
        cout << "5. Insert item at tail . " << endl;
        cout << "6. Insert item at any index . " << endl;
        cout << "7. Sort the Linked list . " << endl;
        cout << "8. Delete Head from the List . " << endl;
        cout << "9. Delete any item from the Linked list . " << endl;
        cout << "0. Exit the program. " << endl;
        cout << "Chose your Option : ";
        int op;
        cin >> op;
        if (op == 1)
        {
            cout << "Enter the number of element in the list : ";
            int n;
            cin >> n;
            while (n--)
            {
                cin >> x;
                if (x >= 0)
                {
                    insert_at_Tail(head, tail, x);
                }
                else
                    break;
            }
        }
        else if (op == 2)
        {
            cout << "Here is the List : ";
            print(head);
        }
        else if (op == 3)
        {
            cout << "Here is the reverse List : ";
            print_reverse(tail);
        }
        else if (op == 4)
        {
            cout << "Enter the Element you want to insert : ";
            int v;
            cin >> v;
            insert_at_Head(head, tail, v);
        }
        else if (op == 5)
        {
            cout << "Enter the Element you want to insert : ";
            int v;
            cin >> v;
            insert_at_Tail(head, tail, v);
        }
        else if (op == 6)
        {
            cout << "Enter the index to insert Element : ";
            int ind;
            cin >> ind;
            cout << "Enter the item to insert : ";
            int v;
            cin >> v;
            insert_at_any_position(head, tail, ind, v);
        }
        else if (op == 7)
        {
            Short_List(head);
        }
        else if (op == 8)
        {
            Head_Delete(head, tail);
        }
        else if (op == 9)
        {
            cout << "Enter the index to delete Element : ";
            int ind;
            cin >> ind;
            Delete_any_item(head, tail, ind);
        }
        else
            break;
    }
    return 0;
}
