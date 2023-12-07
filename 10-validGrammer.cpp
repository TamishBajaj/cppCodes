#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[10];

    cout << "\nThe grammar is as follows:\nS -> bS\nS -> Sa\nS -> ba\n";
    cout << "Enter a string -> ";
    cin >> str;

    if (str[0] != 'b')
    {
        cout << "String is invalid because of incorrect first character";
        exit(0);
    }

    int n = 1;
    while (str[n] == 'b')
        n++;
    if (str[n] != 'a')
    {
        cout << "string does not belong to grammar";
        exit(0);
    }

    n++;
    while (str[n] == 'a')
        n++;
    if (str[n] != '\0')
    {
        cout << "String does not belong to grammar";
        exit(0);
    }

    cout << "string is valid";
    return 0;
}