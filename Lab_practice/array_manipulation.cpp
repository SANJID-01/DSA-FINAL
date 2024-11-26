#include <iostream>
using namespace std;

void CreateArray(int arr[], int &len)
{
    cout << "Enter the number of elements in the array: ";
    cin >> len;
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
}

void DisplayArray(int arr[], int len)
{
    if (len == 0)
    {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Array elements are: ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Selection(int ar[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ar[i] > ar[j])
            {
                swap(ar[i], ar[j]);
            }
        }
    }
}
int Bubble(int ar[], int n)
{
    int counter = 1;
    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (ar[i] > ar[i + 1])
            {
                swap(ar[i], ar[i + 1]);
            }
        }
        counter++;
    }
}
#include <iostream>
using namespace std;

void CreateArray(int arr[], int &len)
{
    cout << "Enter the number of elements in the array: ";
    cin >> len;
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
}

void DisplayArray(int arr[], int len)
{
    if (len == 0)
    {
        cout << "Array is empty." << endl;
        return;
    }
    cout << "Array elements are: ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Selection(int ar[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ar[i] > ar[j])
            {
                swap(ar[i], ar[j]);
            }
        }
    }
}
int Bubble(int ar[], int n)
{
    int counter = 1;
    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (ar[i] > ar[i + 1])
            {
                swap(ar[i], ar[i + 1]);
            }
        }
        counter++;
    }
}
int Partition(int ar[], int low, int high)
{
    int pivot = ar[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (ar[j] < pivot)
        {
            i++;
            swap(ar[i], ar[j]);
        }
    }
    i++;
    swap(ar[i], ar[high]);
    return i;
}
void Quick(int ar[], int low, int high)
{
    if (low < high)
    {
        int pivotInd = Partition(ar, low, high);

        Quick(ar, low, pivotInd - 1);
        Quick(ar, pivotInd + 1, high);
    }
}
int Insertion(int ar[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = ar[i];
        int j = i - 1;
        while (ar[j] > current && j >= 0)
        {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = current;
    }
}

int main()
{
    int arr[100];
    int len = 0;
    char op;

    while (true)
    {
        cout << "\n1. Create an Array" << endl;
        cout << "2. Display the Array" << endl;
        cout << "3. Selection Sort " << endl;
        cout << "4. Bubble sort " << endl;
        cout << "5. Insertion sort " << endl;
        cout << "6. Delete an Element from the Array" << endl;
        cout << "0. Exit" << endl;
        cout << endl
             << "Enter your option: ";
        cin >> op;

        switch (op)
        {
        case '1':
            CreateArray(arr, len);
            break;
        case '2':
            DisplayArray(arr, len);
            cout << endl;
            break;
        case '3':
        {
            cout << "Selection Sort applied : " << endl;
            Selection(arr, len);
            break;
        }
        case '4':
        {
            cout << "Bubble Sort applied : " << endl;
            Bubble(arr, len);
            break;
        }
        case '5':
        {
            cout << "Quick Sort applied : " << endl;
            Selection(arr, len);
            break;
        }
        case '6':
        {
            cout << "Insertaion Sort applied : " << endl;
            Insertion(arr, len);
            break;
        }

        case '0':
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}

int Insertion(int ar[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = ar[i];
        int j = i - 1;
        if (ar[j] > current && j >= 0)
        {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = current;
    }
}

int main()
{
    int arr[100];
    int len = 0;
    char op;

    while (true)
    {
        cout << "\n1. Create an Array" << endl;
        cout << "2. Display the Array" << endl;
        cout << "3. Find the Index of an Element" << endl;
        cout << "4. Insert an Element into the Array" << endl;
        cout << "5. Replace an Element in the Array" << endl;
        cout << "6. Delete an Element from the Array" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your option: ";
        cin >> op;

        switch (op)
        {
        case '1':
            CreateArray(arr, len);
            break;
        case '2':
            DisplayArray(arr, len);
            break;
        case '3':
        {
            cout << "Selection Sort applied : " << endl;
            Selection(arr, len);
            break;
        }
        case '4':
        {
            cout << "Bubble Sort applied : " << endl;
            Bubble(arr, len);
            break;
        }
        case '5':
        {
            cout << "Quick Sort applied : " << endl;
            Quick(arr, 0, len - 1);
            break;
        }
        case '6':
        {
            cout << "Insertaion Sort applied : " << endl;
            Selection(arr, len);
            break;
        }

        case '0':
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}
