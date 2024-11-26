#include <iostream>
using namespace std;

void inputString(char str[])
{
    cout << "Enter a string: ";
    cin >> str;
}

void traverseString(char str[])
{
    cout << "Characters in the string: ";
    for (int i = 0; str[i] != '\0'; i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;
}

int stringLength(char str[])
{
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length;
}

void substring(char str[], int start, int length)
{
    cout << "Substring: ";
    for (int i = start; i < start + length && str[i] != '\0'; i++)
    {
        cout << str[i];
    }
    cout << endl;
}

bool compareStrings(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            return false;
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

char stringIndex(char str[], int index)
{
    return str[index];
}

void concatenateStrings(char str1[], char str2[])
{
    int i = 0, j = 0;
    while (str1[i] != '\0')
        i++;
    while (str2[j] != '\0')
    {
        str1[i++] = str2[j++];
    }
    str1[i] = '\0';
}

void insertString(char str[], char toInsert[], int position)
{
    char result[100];
    int i = 0, j = 0, k = 0;

    while (i < position && str[i] != '\0')
        result[k++] = str[i++];
    while (toInsert[j] != '\0')
        result[k++] = toInsert[j++];
    while (str[i] != '\0')
        result[k++] = str[i++];

    result[k] = '\0';
    cout << "Resultant String: " << result << endl;
}

void deleteString(char str[], int position, int length)
{
    char result[100];
    int i = 0, j = 0;

    while (i < position)
        result[j++] = str[i++];
    i += length;
    while (str[i] != '\0')
        result[j++] = str[i++];

    result[j] = '\0';
    cout << "Resultant String: " << result << endl;
}

int main()
{
    char str[100], str2[100];
    int choice, start, length, position;

    while (true)
    {
        cout << "\nString Operations Menu:\n";
        cout << "1. Input String\n2. Traverse String\n3. String Length\n4. Substring\n5. Compare Strings\n6. Concatenate Strings\n7. Insert String\n8. Delete String\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            inputString(str);
            break;
        case 2:
            traverseString(str);
            break;
        case 3:
            cout << "Length: " << stringLength(str) << endl;
            break;
        case 4:
            cout << "Enter start position and length: ";
            cin >> start >> length;
            substring(str, start, length);
            break;
        case 5:
            cout << "Enter another string to compare: ";
            cin >> str2;
            cout << (compareStrings(str, str2) ? "Strings are equal." : "Strings are not equal.") << endl;
            break;
        case 6:
            cout << "Enter another string to concatenate: ";
            cin >> str2;
            concatenateStrings(str, str2);
            cout << "After concatenation: " << str << endl;
            break;
        case 7:
            cout << "Enter string to insert and position: ";
            cin >> str2 >> position;
            insertString(str, str2, position);
            break;
        case 8:
            cout << "Enter position and length to delete: ";
            cin >> position >> length;
            deleteString(str, position, length);
            break;
        case 9:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
