#include <iostream>
using namespace std;


int main()
{
    int M;
    int N;
    int X1, Y1, X2, Y2;
    cin >> N;
    cin >> M;
    cin >> X1;
    cin >> Y1;
    cin >> X2;
    cin >> Y2;
    bool checked = false;
    if (abs(X1 - X2) == abs(Y1 - Y2))
        checked = false;
    else
        checked = true;

    if (checked)
        cout << "YES";
    else
        cout << "NO";


    
    return 0;
}