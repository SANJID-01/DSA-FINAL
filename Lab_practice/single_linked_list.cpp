#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_Tail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insert_at_Head(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insert_at_any_position(Node *&head, int index, int val)
{
    if (index == 0)
    {
        insert_at_Head(head, val);
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
    temp->next = newNode;
}

void Head_Delete(Node *&head)
{
    if (head == NULL)
        return;
    Node *delete_Node = head;
    head = head->next;
    delete delete_Node;
}

void Delete_any_item(Node *&head, int ind)
{
    if (head == NULL)
    {
        cout << endl
             << "List is empty" << endl;
        return;
    }
    if (ind == 0)
    {
        Head_Delete(head);
        return;
    }
    Node *temp = head;
    for (int i = 0; i < ind - 1; i++)
    {
        if (temp == NULL || temp->next == NULL)
        {
            cout << endl
                 << ".....Invalid Index ." << endl;
            return;
        }
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    if (deleteNode == NULL)
    {
        cout << endl
             << ".....Invalid Index ." << endl;
        return;
    }
    temp->next = deleteNode->next;
    delete deleteNode;
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

void print_reverse(Node *head)
{
    if (head == NULL)
        return;
    print_reverse(head->next);
    cout << head->val << " ";
}

int main()
{
    Node *head = NULL;
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
        cout << endl
             << "Chose your Option : ";
        int op;
        cin >> op;
        if (op == 1)
        {
            cout << endl
                 << "Enter the number of element in the list : ";
            int n;
            cin >> n;
            while (n--)
            {
                cin >> x;
                if (x >= 0)
                {
                    insert_at_Tail(head, x);
                }
                else
                    break;
            }
        }
        else if (op == 2)
        {
            cout << endl
                 << "Here is the List : ";
            print(head);
        }
        else if (op == 3)
        {
            cout << endl
                 << "Here is the reverse List : ";
            print_reverse(head);
            cout << endl;
        }
        else if (op == 4)
        {
            cout << endl
                 << "Enter the Element you want to insert : ";
            int v;
            cin >> v;
            insert_at_Head(head, v);
        }
        else if (op == 5)
        {
            cout << endl
                 << "Enter the Element you want to insert : ";
            int v;
            cin >> v;
            insert_at_Tail(head, v);
        }
        else if (op == 6)
        {
            cout << endl
                 << "Enter the index to insert Element : ";
            int ind;
            cin >> ind;
            cout << endl
                 << "Enter the item to insert : ";
            int v;
            cin >> v;
            insert_at_any_position(head, ind, v);
        }
        else if (op == 7)
        {
            Short_List(head);
        }
        else if (op == 8)
        {
            Head_Delete(head);
        }
        else if (op == 9)
        {
            cout << endl
                 << "Enter the index to delete Element : ";
            int ind;
            cin >> ind;
            Delete_any_item(head, ind);
        }
        else
            break;
    }
    return 0;
}