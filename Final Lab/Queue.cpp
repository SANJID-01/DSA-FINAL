#include <bits/stdc++.h>
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

class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    // Push a value into the queue (insert at tail)
    void push(int val)
    {
        sz++;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }

    // Pop a value from the queue (delete from head)
    void pop()
    {
        if (sz == 0)
        {
            cout << "Queue is empty. Cannot pop.\n";
            return;
        }
        sz--;
        Node *deleteNode = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }
        delete deleteNode;
    }

    // Get the front value of the queue
    int front()
    {
        if (sz == 0)
        {
            cout << "Queue is empty. No front element.\n";
            return -1;
        }
        return head->val;
    }

    // Return the size of the queue
    int size()
    {
        return sz;
    }

    // Check if the queue is empty
    bool empty()
    {
        return sz == 0;
    }

    // Display the queue from the front
    void display()
    {
        if (sz == 0)
        {
            cout << "Queue is empty.\n";
            return;
        }
        Node *temp = head;
        cout << "Queue: ";
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    myQueue q;
    char op;
    int value;

    while (true)
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert an element into the queue\n";
        cout << "2. Delete an element from the queue\n";
        cout << "3. Display the queue\n";
        cout << "4. Display the front element\n";
        cout << "5. Check the size of the queue\n";
        cout << "6. Check if the queue is empty\n";
        cout << "0. Exit\n";
        cout << "Enter your option: ";
        cin >> op;

        switch (op)
        {
        case '1':
            cout << "Enter the value to insert: ";
            cin >> value;
            q.push(value);
            cout << "Value " << value << " inserted into the queue.\n";
            break;

        case '2':
            if (!q.empty())
            {
                cout << "Deleting front element: " << q.front() << "\n";
                q.pop();
            }
            else
            {
                cout << "Queue is empty. Cannot delete.\n";
            }
            break;

        case '3':
            q.display();
            break;

        case '4':
            if (!q.empty())
            {
                cout << "Front element: " << q.front() << "\n";
            }
            else
            {
                cout << "Queue is empty. No front element.\n";
            }
            break;

        case '5':
            cout << "Queue size: " << q.size() << "\n";
            break;

        case '6':
            if (q.empty())
            {
                cout << "Queue is empty.\n";
            }
            else
            {
                cout << "Queue is not empty.\n";
            }
            break;

        case '0':
            cout << "Exiting the program.\n";
            return 0;

        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
