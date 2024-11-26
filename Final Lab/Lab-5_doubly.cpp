#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int val;
    node *next;
    node *prev;

    node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList
{
private:
    node *head, *tail;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void createRandomList(int n)
    {
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            int val = rand() % 100;
            insertAtEnd(val);
        }
    }

    void insertAtEnd(int val)
    {
        node *newNode = new node(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void traverse()
    {
        node *temp = head;
        cout << "Doubly Linked List: ";
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void search(int val)
    {
        node *temp = head;
        int pos = 0;
        while (temp)
        {
            if (temp->val == val)
            {
                cout << "Item " << val << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Item " << val << " not found in the list.\n";
    }

    void sortList()
    {
        if (!head)
            return;

        for (node *i = head; i; i = i->next)
        {
            for (node *j = i->next; j; j = j->next)
            {
                if (i->val > j->val)
                    swap(i->val, j->val);
            }
        }
        cout << "List sorted successfully.\n";
    }

    void insertSorted(int val)
    {
        node *newNode = new node(val);

        if (!head)
        {
            head = tail = newNode;
            return;
        }

        if (val < head->val)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        node *temp = head;
        while (temp->next && temp->next->val < val)
            temp = temp->next;

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode;

        temp->next = newNode;
    }

    void deleteItem(int val)
    {
        node *temp = head;

        while (temp)
        {
            if (temp->val == val)
            {
                if (temp->prev)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;

                if (temp->next)
                    temp->next->prev = temp->prev;
                else
                    tail = temp->prev;

                delete temp;
                cout << "Item " << val << " deleted successfully.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Item " << val << " not found in the list.\n";
    }
};

int main()
{
    DoublyLinkedList list;
    int n, item;
    char op;

    while (true)
    {
        cout << "\n1. Create a random doubly linked list\n";
        cout << "2. Display the doubly linked list\n";
        cout << "3. Search for an item\n";
        cout << "4. Sort the doubly linked list\n";
        cout << "5. Insert an item into the sorted list\n";
        cout << "6. Delete an item from the list\n";
        cout << "0. Exit\nEnter your option: ";
        cin >> op;

        switch (op)
        {
        case '1':
            cout << "Enter the number of nodes: ";
            cin >> n;
            list.createRandomList(n);
            cout << "Random doubly linked list created.\n";
            break;

        case '2':
            list.traverse();
            break;

        case '3':
            cout << "Enter the item to search: ";
            cin >> item;
            list.search(item);
            break;

        case '4':
            list.sortList();
            break;

        case '5':
            cout << "Enter the item to insert into the sorted list: ";
            cin >> item;
            list.insertSorted(item);
            break;

        case '6':
            cout << "Enter the item to delete: ";
            cin >> item;
            list.deleteItem(item);
            break;

        case '0':
            exit(0);

        default:
            cout << "Invalid option! Please try again.\n";
        }
    }

    return 0;
}
