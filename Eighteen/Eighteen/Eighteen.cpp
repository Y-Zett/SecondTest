
#include<iostream>
using namespace std;

int main()
{
    float year;
    cin >> year;
    int tmp = year;
    tmp %= 4;
    int temp = year;
    temp %= 100;
    int temper = year;
    temper %= 400;
    bool checker = false;
    if (tmp == 0) {
        checker = true;
        if (temp == 0) {
            checker = false;
        }
        if (temper == 0) {
            checker = true;
        }
    }
    if (checker == false)
        cout << "NO";
    else
        cout << "YES";
       

}