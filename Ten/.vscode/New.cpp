#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string S;
    cin >> S;
    const int p = 31;
    long l = S.length();
    long long* power = new long long [l];
    power[0] = 1;
    for (int i = 1; i < l; i++)
        power[i] = power[i - 1] * p;
    long long* hash = new long long [S.length()];
    for (long i = 0; i < S.length(); i++)
    {
        hash[i] = (S[i] -  'a' + 2) * power[i];
        if (i > 0)
            hash[i] += hash[i - 1];
    }

    long result = 0;
    for (int j = 1; j <= l; j++)
    {
        //vector <long long> subhash(l - j + 1);
        long long* subhash = new long long [l - j + 1];  
        for (int i = 0; i < l - j + 1; i++)
        {
            long long h = hash[i + j - 1];
            if (i > 0)
                h -= hash[i - 1];
            h *= power[l - i - 1];
			subhash[i] = h;
        }

        sort(subhash, subhash + l - j + 1);
	//	for (long i = 0)
    //    result += subhash.size();
    }

    cout << result;

    delete power;
    return 0; 
}