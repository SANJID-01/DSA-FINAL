#include <bits/stdc++.h>
#define ll long long int
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
void BubbleSort(int arr[], int len) {
    int comparisons = 0, swaps = 0;
    
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                // Swap if the element is greater than the next one
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }

    cout << "Bubble Sort completed. Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[100];
    int len = 0;
    char op;

    while (true)
    {
        cout << "\n1. Create an Array" << endl;
        cout << "2. Display the Array" << endl;
        cout << "3. Sort the Array using BUBBLE sort " << endl;
        cout << "4. Sort the Array using SELECTION sort" << endl;
        cout << "5. Sort the Array using Quick Sort" << endl;
        cout << "6. Sort the Array using Insertion Sort" << endl;
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
                cout<<endl<<"BUBBLE sorting applied : "<<endl;
                BubbleSort(arr, len);
        }
    }
    return 0;
}