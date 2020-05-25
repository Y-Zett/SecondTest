#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;

    bool check = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != str[0] && check)
        {
            check = false;
        }
    }
    if (check)
    {
        cout << "-1";
        return 0;
    }

    bool secondcheck = true;

    for (int i = 0, j = str.length() - 1; i < j + 1; i++, j--)
    {
        if (str[i] != str[j])
        {
            secondcheck = false;
        }
    }

    int answer = secondcheck?  str.length() - 1 : str.length(); 
    cout << answer;
    
    return 0;
}