// #include <iostream>
// #include <string>
// using namespace std;

// string MySubString(const string &str, int in, int nofc)
// {
//     if (in < 0 || in >= str.length() || nofc < 0 || in + nofc > str.length())
//     {
//         cout << "Invalid index or number of characters." << endl;
//         return "";
//     }
//     string result = "";
//     for (int i = in; i < in + nofc; i++)
//     {
//         result += str[i];
//     }
//     return result;
// }

// int MyStrLength(const string &str)
// {
//     int length = 0;
//     while (str[length] != '\0')
//     {
//         length++;
//     }
//     return length;
// }

// string MyConcate(const string &str1, const string &str2)
// {
//     string result = str1;
//     for (int i = 0; str2[i] != '\0'; i++)
//     {
//         result += str2[i];
//     }
//     return result;
// }

// int IndexOfPattern(const string &str, const string &pattern)
// {
//     int strLen = MyStrLength(str);
//     int patLen = MyStrLength(pattern);

//     for (int i = 0; i <= strLen - patLen; i++)
//     {
//         int j = 0;
//         while (j < patLen && str[i + j] == pattern[j])
//         {
//             j++;
//         }
//         if (j == patLen)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// string InsertPattern(const string &str, const string &pattern, int index)
// {
//     if (index < 0 || index > MyStrLength(str))
//     {
//         cout << "Invalid index." << endl;
//         return str;
//     }

//     string result = "";
//     for (int i = 0; i < index; i++)
//     {
//         result += str[i];
//     }
//     result += pattern;
//     for (int i = index; str[i] != '\0'; i++)
//     {
//         result += str[i];
//     }
//     return result;
// }

// string ReplacePattern(const string &str, const string &oldPattern, const string &newPattern)
// {
//     int index = IndexOfPattern(str, oldPattern);
//     if (index == -1)
//     {
//         cout << "Pattern not found." << endl;
//         return str;
//     }

//     string result = "";
//     for (int i = 0; i < index; i++)
//     {
//         result += str[i];
//     }
//     result += newPattern;
//     for (int i = index + MyStrLength(oldPattern); str[i] != '\0'; i++)
//     {
//         result += str[i];
//     }
//     return result;
// }

// string DeleteString(const string &str, const string &pattern)
// {
//     int index = IndexOfPattern(str, pattern);
//     if (index == -1)
//     {
//         cout << "Pattern not found." << endl;
//         return str;
//     }

//     string result = "";
//     for (int i = 0; i < index; i++)
//     {
//         result += str[i];
//     }
//     for (int i = index + MyStrLength(pattern); str[i] != '\0'; i++)
//     {
//         result += str[i];
//     }
//     return result;
// }

// int main()
// {
//     char op;
//     int in, nofc;
//     string Str1, Str2, Str3;

//     while (true)
//     {
//         cout << "\n1. Input a String" << endl;
//         cout << "2. Length of the String" << endl;
//         cout << "3. Display the String" << endl;
//         cout << "4. Sub-string of the String" << endl;
//         cout << "5. Concatenation of two Strings" << endl;
//         cout << "6. Indexing a pattern in a String" << endl;
//         cout << "7. Inserting a pattern in a String" << endl;
//         cout << "8. Replacing a pattern in a String" << endl;
//         cout << "9. Delete a String" << endl;
//         cout << "0. Exit" << endl;
//         cout << "Enter your option: ";
//         cin >> op;
//         cin.ignore();

//         switch (op)
//         {
//         case '1':
//             cout << "\nEnter a line of text string:" << endl;
//             getline(cin, Str1);
//             break;
//         case '2':
//             cout << "\nThe length of the string is " << MyStrLength(Str1) << endl;
//             break;
//         case '3':
//             cout << "\nInputted String is:" << endl;
//             cout << Str1 << endl;
//             break;
//         case '4':
//             cout << "\nEnter the index of the sub-string: ";
//             cin >> in;
//             cout << "Enter the number of characters (NOFC) for the sub-string: ";
//             cin >> nofc;
//             cin.ignore();
//             cout << "\nThe sub-string is:" << endl;
//             cout << MySubString(Str1, in, nofc) << endl;
//             break;
//         case '5':
//             cout << "\nEnter second string:" << endl;
//             getline(cin, Str2);
//             Str3 = MyConcate(Str1, Str2);
//             cout << "\nConcatenated String is:" << endl;
//             cout << Str3 << endl;
//             break;
//         case '6':
//         {
//             cout << "\nEnter the pattern to find: ";
//             getline(cin, Str2);
//             int index = IndexOfPattern(Str1, Str2);
//             if (index == -1)
//             {
//                 cout << "Pattern not found." << endl;
//             }
//             else
//             {
//                 cout << "Pattern found at index " << index << "." << endl;
//             }
//             break;
//         }
//         case '7':
//         {
//             cout << "\nEnter the pattern to insert: ";
//             getline(cin, Str2);
//             cout << "Enter the index to insert at: ";
//             cin >> in;
//             cin.ignore();
//             Str1 = InsertPattern(Str1, Str2, in);
//             cout << "\nUpdated String is:" << endl;
//             cout << Str1 << endl;
//             break;
//         }
//         case '8':
//         {
//             cout << "\nEnter the pattern to replace: ";
//             getline(cin, Str2);
//             cout << "Enter the new pattern: ";
//             getline(cin, Str3);
//             Str1 = ReplacePattern(Str1, Str2, Str3);
//             cout << "\nUpdated String is:" << endl;
//             cout << Str1 << endl;
//             break;
//         }
//         case '9':
//         {
//             cout << "\nEnter the pattern to delete: ";
//             getline(cin, Str2);
//             Str1 = DeleteString(Str1, Str2);
//             cout << "\nUpdated String is:" << endl;
//             cout << Str1 << endl;
//             break;
//         }
//         case '0':
//             cout << "Exiting the program." << endl;
//             return 0;
//         default:
//             cout << "Invalid option. Please try again." << endl;
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int sz = 0;
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

void PUSH(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    sz++;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void POP(Node *&head, Node *&tail)
{
    if (head == NULL)
        return;
    Node *deleteNode = tail;
    sz--;
    tail = tail->prev;
    if (tail != NULL)
    {
        tail->next = NULL;
    }
    else
    {
        head = NULL;
    }
    delete deleteNode;
}

// int x = int SIZE(int sz);

void Display(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int x;
    while (true)
    {
        cout << "1. Create a Stack using push operation . " << endl;
        cout << "2. Display the Stack . " << endl;
        cout << "3. Insert item to the Stack Using Push. " << endl;
        cout << "4. Delete item from the stack using Pop . " << endl;
        cout << "5. find the size of the Stack . " << endl;
        cout << "0. Exit the program. " << endl;
        cout << "Chose your Option : ";
        int op;
        cin >> op;
        if (op == 1)
        {
            cout << "Enter the number of element in the list : ";
            int n;
            cin >> n;
            while (n--)
            {
                cin >> x;
                if (x >= 0)
                {
                    PUSH(head, tail, x);
                }
                else
                    break;
            }
        }
        else if (op == 2)
        {
            cout << "Here is the reverse List : ";
            Display(tail);
        }
        else if(op==3)
        {
            cout<<"Add item to the Stack Using PUSH operation : "; 
            int x; 
            cin>>x; 
            PUSH(head, tail, x);
        }
         else if(op == 4)
         {
            cout<<"Delet Item from the Stack using POP operation : "; 
            POP(head, tail);
         }
         else if (op==5)
         {
            cout<<"The size of the Stack is : "; 
            
         }
        else
            break;
    }
    return 0;
}
