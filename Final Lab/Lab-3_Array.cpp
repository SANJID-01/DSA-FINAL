#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int SearchItem(int *data, int n, int item)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (item == data[i])
        {
            cnt++;
        }
    }
    return cnt;
}

void Insert(int *LA, int *n, int k, int item)
{
    int j = *n;
    while (j >= k)
    {
        LA[j + 1] = LA[j];
        j--;
    }
    LA[k] = item;
    *n = *n + 1;
}

void Delete(int *LA, int *n, int k, int &item)
{
    item = LA[k];
    int j = *n;
    for (int i = k; i < j; i++)
    {
        LA[i] = LA[i + 1];
    }
    *n = *n - 1;
}

int main()
{
    int n, item, k, cnt;
    int LA[10000];
    srand(time(NULL));
    char op;

    while (true)
    {
        cout << "\n1. Create an Array\n";
        cout << "2. Display the Array\n";
        cout << "3. Search an item from the Array\n";
        cout << "4. Insert an item into the Array\n";
        cout << "5. Delete an item from the Array\n";
        cout << "0. Exit\nEnter your option: ";
        cin >> op;

        switch (op)
        {
        case '1':
            cout << "\nEnter the amount of numbers: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                LA[i] = rand() % 1000;
            }
            break;

        case '2':
            cout << "\nThe " << n << " Numbers are as follows:\n";
            for (int i = 0; i < n; i++)
            {
                cout << LA[i] << " ";
            }
            cout << endl;
            break;

        case '3':
            cout << "\nEnter the item, which you want to search: ";
            cin >> item;
            cnt = SearchItem(LA, n, item);
            if (cnt == 0)
                cout << "The " << item << " item not found in the list\n";
            else
                cout << "Item " << item << " found in this array " << cnt << " times\n";
            break;

        case '4':
            cout << "\nEnter the value to insert: ";
            cin >> item;
            cout << "\nEnter the Location: ";
            cin >> k;
            Insert(LA, &n, k, item);
            break;

        case '5':
            cout << "\nEnter the location to delete from: ";
            cin >> k;
            Delete(LA, &n, k, item);
            break;

        case '0':
            exit(0);
            break;

        default:
            cout << "Invalid option! Please try again.\n";
        }
    }

    return 0;
}
