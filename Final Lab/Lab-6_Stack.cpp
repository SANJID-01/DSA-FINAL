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

class myStack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

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
        newNode->prev = tail;
        tail->next = newNode;
        tail = tail->next;
    }

    void pop()
    {
        if (sz == 0)
        {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        sz--;
        Node *deleteNode = tail;
        tail = tail->prev;
        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        delete deleteNode;
    }

    int top()
    {
        if (sz == 0)
        {
            cout << "Stack is empty. No top element.\n";
            return -1;
        }
        return tail->val;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        return sz == 0;
    }
};

int main()
{
    myStack st;
    char op;
    int value;

    while (true)
    {
        cout << "1. Push a value in to the stack\n";
        cout << "2. Pop a value from the stack\n";
        cout << "3. View the top element of the stack\n";
        cout << "4. Check the size of the stack\n";
        cout << "5. Check if the stack is empty\n";
        cout << "6. Display the stack\n";
        cout << "0. Exit\n";
        cout << "Enter your option: ";
        cin >> op;

        switch (op)
        {
        case '1':
            cout << "Enter the value to push: ";
            cin >> value;
            st.push(value);
            cout << "Value " << value << " pushed onto the stack.\n";
            break;

        case '2':
            if (!st.empty())
            {
                cout << "Popping value: " << st.top() << "\n";
                st.pop();
            }
            else
            {
                cout << "Stack is empty. Cannot pop.\n";
            }
            break;

        case '3':
            if (!st.empty())
            {
                cout << "Top element: " << st.top() << "\n";
            }
            else
            {
                cout << "Stack is empty. No top element.\n";
            }
            break;

        case '4':
            cout << "Stack size: " << st.size() << "\n";
            break;

        case '5':
            if (st.empty())
            {
                cout << "Stack is empty.\n";
            }
            else
            {
                cout << "Stack is not empty.\n";
            }
            break;

        case '6':
        {
            cout << "Stack is : " << endl;
            while (!st.empty())
            {
                cout << st.top() << " ";
                st.pop();
            }
            cout << endl;
            break;
        }

        case '0':
            cout << "Exiting the program.\n";
            exit(0);

        default:
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
