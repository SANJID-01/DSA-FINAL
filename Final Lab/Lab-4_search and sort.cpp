#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Bubble(int *Data, int N)
{
    int k, ptr, temp, count = 0;
    for (k = 0; k < N - 1; k++)
    {
        ptr = 0;
        while (ptr < N - k - 1)
        {
            if (Data[ptr] > Data[ptr + 1])
            {
                count++;
                temp = Data[ptr];
                Data[ptr] = Data[ptr + 1];
                Data[ptr + 1] = temp;
            }
            ptr++;
        }
    }
    return count;
}

int LinearSearch(int *Data, int N, int item)
{
    int loc = -1;
    for (int i = 0; i < N; i++)
    {
        if (item == Data[i])
        {
            loc = i;
            break;
        }
    }
    return loc;
}

int binarySearch(int *Data, int lb, int ub, int item)
{
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;

        if (Data[mid] == item)
            return mid;

        if (Data[mid] < item)
            lb = mid + 1;

        else
            ub = mid - 1;
    }

    return -1;
}

int selectionSort(int arr[], int n)
{
    int min_idx, temp, count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        if (min_idx != i)
        {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }

        count++;
    }
    return count;
}

int main()
{
    int n, loc, item, bsc;
    int Data[10000];
    srand(time(NULL));
    clock_t begin, end;
    double time_spent;

    char op;
    while (true)
    {
        cout << "\n1. Create an Array\n";
        cout << "2. Display the Array\n";
        cout << "3. Sort the Array using Bubble Sort\n";
        cout << "4. Sort the Array using Selection Sort\n";
        cout << "5. Search an Item using linear search\n";
        cout << "6. Search an Item using Binary search\n";
        cout << "0. Exit\nEnter your option: ";
        cin >> op;

        switch (op)
        {
        case '1':
            cout << "\nEnter the amount of numbers: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                Data[i] = rand() % 1000;
            }
            break;

        case '2':
            cout << "\nThe " << n << " Numbers are as follows:\n";
            for (int i = 0; i < n; i++)
            {
                cout << Data[i] << " ";
            }
            cout << endl;
            break;

        case '3':
            begin = clock();
            bsc = Bubble(Data, n);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            cout << "\nTotal time spent: " << time_spent << " seconds\n";
            cout << "Total interchanges: " << bsc << endl;
            break;

        case '4':
            begin = clock();
            bsc = selectionSort(Data, n);
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            cout << "\nTotal time spent: " << time_spent << " seconds\n";
            cout << "Total interchanges: " << bsc << endl;
            break;

        case '5':
            cout << "\nEnter the item for search: ";
            cin >> item;
            loc = LinearSearch(Data, n, item);
            if (loc == -1)
                cout << "\nItem not found\n";
            else
                cout << "\nItem found at location " << loc << endl;
            break;

        case '6':
            cout << "\nEnter the item for search: ";
            cin >> item;
            loc = binarySearch(Data, 0, n - 1, item);
            if (loc == -1)
                cout << "\nItem not found\n";
            else
                cout << "\nItem found at location " << loc << endl;
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
