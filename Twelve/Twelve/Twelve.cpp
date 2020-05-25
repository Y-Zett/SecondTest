#include <iostream>
using namespace std;
int main()
{	
	long num;
	cin>>num;
	if (num % 10 != 0)
		cout << num % 10;
	else
		cout << "NO";
}
