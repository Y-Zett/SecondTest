#include <iostream>
#include <vector>
#include <string>
using namespace std;


void Print(vector<long> array) 
{
    cout << "[";
    for (long i = 0; i < array.size(); i++) 
    {
        cout << array[i];
        if (i != array.size() - 1) 
        {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

void Print(vector <bool> array)
{
    cout << "[";
    for (long i = 0; i < array.size(); i++)
    {
        cout << array[i];
        if (i != array.size() - 1)
        {
            cout << ",";
        }
    }
    cout << "]" << endl; 
}

int main()
{
    string S; 
    long Q;
    cin >> S;
    cin >> Q;
    vector <long> L(Q);
    vector <long> R(Q);
    vector <bool> checked(S.length(), false);

    for (int i = 0; i < Q; i++)
    {
        long input[2];
        cin >> input[0] >> input[1];

        if (input[0] > input[1])
        {
            int temp = input[0];
            input[0] = input[1];
            input[1] = temp;
        }

        input[0] --;

        if (input[0] > input[1])
        {
            int temp = input[0];
            input[0] = input[1];
            input[1] = temp;
        }

        L[i] = input[0];
        R[i] = input[1];
        checked[L[i]] = !checked[L[i]];
        if (R[i] != S.length())
            checked[R[i]] = !checked[R[i]];
    }

    bool isdeal = false;
    for (long i = 0; i < S.length(); i++)
    {
        if (checked[i])
            isdeal = !isdeal;

        if (isdeal) {
            if (islower(S[i]))
                S[i] = (char)toupper(S[i]);
            else
                S[i] = (char)tolower(S[i]);
        }
    }

    cout << S;
    return 0;
}
