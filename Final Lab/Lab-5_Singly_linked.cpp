#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class List
{
public:
    int info;
    List *next;
    List(int val)
    {
        info = val;
        next = nullptr;
    }
};

void Display(List *Start)
{
    List *Ptr = Start;
    while (Ptr != nullptr)
    {
        cout << Ptr->info << " ";
        Ptr = Ptr->next;
    }
    cout << endl;
}

List *CreateList(List *Start, int n)
{
    List *Ptr = nullptr;
    while (n)
    {
        int val = (rand() % 100) + 1;
        if (Start == nullptr)
        {
            Start = new List(val);
            Ptr = Start;
        }
        else
        {
            Ptr->next = new List(val);
            Ptr = Ptr->next;
        }
        n--;
    }
    return Start;
}

List *FindA(List *Start, int item)
{
    List *Loc = nullptr, *Save = nullptr, *Ptr = Start;
    if (Start == nullptr)
    {
        return nullptr;
    }
    if (item < Start->info)
    {
        return nullptr;
    }
    Save = Start;
    Ptr = Start->next;
    while (Ptr != nullptr)
    {
        if (item < Ptr->info)
        {
            Loc = Save;
            return Loc;
        }
        Save = Ptr;
        Ptr = Ptr->next;
    }
    Loc = Save;
    return Loc;
}

List *InsLoc(List *Start, int item, List *Loc)
{
    List *New = new List(item);
    if (Loc == nullptr)
    {
        New->next = Start;
        Start = New;
    }
    else
    {
        New->next = Loc->next;
        Loc->next = New;
    }
    return Start;
}

List *SortedList(List *Start, int n)
{
    while (n)
    {
        int item = (rand() % 1000) + 1;
        List *Loc = FindA(Start, item);
        Start = InsLoc(Start, item, Loc);
        n--;
    }
    return Start;
}

bool SearchItem(List *Start, int item)
{
    List *Ptr = Start;
    while (Ptr != nullptr)
    {
        if (Ptr->info == item)
        {
            return true;
        }
        Ptr = Ptr->next;
    }
    return false;
}

List *CreateUniqueList(List *Start, int n)
{
    while (n)
    {
        int item = (rand() % 1000) + 1;
        if (!SearchItem(Start, item))
        {
            List *New = new List(item);
            New->next = Start;
            Start = New;
        }
        else
        {
            n++;
        }
        n--;
    }
    return Start;
}

List *DeleteItem(List *Start, int item)
{
    List *Ptr = Start, *Prev = nullptr;
    while (Ptr != nullptr)
    {
        if (Ptr->info == item)
        {
            if (Prev == nullptr)
            {
                Start = Ptr->next;
            }
            else
            {
                Prev->next = Ptr->next;
            }
            delete Ptr;
            cout << "\nItem deleted successfully!" << endl;
            return Start;
        }
        Prev = Ptr;
        Ptr = Ptr->next;
    }
    cout << "\nItem not found!" << endl;
    return Start;
}

int main()
{
    int n, item;
    List *Start = nullptr;
    srand(time(NULL));
    int op;
    while (1)
    {
        cout << "\n1. Create a Random Linked List\n";
        cout << "2. Display the Linked List\n";
        cout << "3. Search an Item from the List\n";
        cout << "4. Create a Linked List Avoiding Duplicate Numbers\n";
        cout << "5. Create a Sorted Linked List\n";
        cout << "6. Delete an Item from the List\n";
        cout << "0. Exit\nEnter your option: ";
        cin >> op;

        cout << endl;

        switch (op)
        {
        case 1:
            cout << "Enter amount of items: ";
            cin >> n;
            if (n)
            {
                Start = CreateList(Start, n);
            }
            else
            {
                cout << "Invalid input!" << endl;
            }
            break;
        case 2:
            cout << "\nThe list as follows:\n";
            Display(Start);
            break;
        case 3:
            cout << "Enter the item to search: ";
            cin >> item;
            if (SearchItem(Start, item))
            {
                cout << "\nItem found in the list!" << endl;
            }
            else
            {
                cout << "\nItem not found in the list!" << endl;
            }
            break;
        case 4:
            cout << "Enter amount of unique items: ";
            cin >> n;
            if (n)
            {
                Start = CreateUniqueList(Start, n);
            }
            else
            {
                cout << "Invalid input!" << endl;
            }
            break;
        case 5:
            cout << "Enter amount of items: ";
            cin >> n;
            if (n)
            {
                Start = SortedList(Start, n);
            }
            else
            {
                cout << "Invalid input!" << endl;
            }
            break;
        case 6:
            cout << "Enter the item to delete: ";
            cin >> item;
            Start = DeleteItem(Start, item);
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "\nInvalid option!" << endl;
        }
    }
    return 0;
}
