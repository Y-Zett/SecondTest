#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long multiplication = 1;
    long long mod = 10e9 + 7;

    long long N, K;
    cin >> N;
    cin >> K;
    vector<long long> A(N);
    for (long i = 0; i < N; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    long long leftB = 0;
    long long rightB = A.size() - 1;
    long long lastEl = A[rightB];
    long long lastMinus = false;
    lastEl < 0 ? lastMinus = true : lastMinus = false;

    if (K % 2 == 1)
    {
        if (lastEl > 0)
        {
            multiplication *= lastEl;
            rightB--;
            K--;
        }
    }

    while (K >= 1)
    {
        if (K == 0)
            break;
        else
        {
            if (K == 1)
            {
                multiplication *= A[rightB];
                rightB--;
                K--;
            }
            else
            {
                long long left = A[leftB] * A[leftB + 1];
                long long right = A[rightB] * A[rightB - 1];
                if (left >= right && !lastMinus)
                {
                    multiplication *= left;
                    leftB += 2;
                }
                else
                {
                    if (left < right && lastMinus)
                    {
                        multiplication *= left;
                        leftB += 2;
                    }
                    else
                    {
                        if (left < right && !lastMinus)
                        {
                            multiplication *= right;
                            rightB -= 2;
                        }
                        else
                        {
                            if (left >= right && lastMinus)
                            {
                                multiplication *= right;
                                rightB -= 2;
                            }
                            else
                            {
                                multiplication *= right;
                                rightB -= 2;
                            }
                        }
                    }
                }

                K -= 2;
            }
        }
        if (abs(multiplication) < mod)
        {
            multiplication %= mod;
            if (multiplication < 0)
                multiplication += mod;
        }

        while (abs(multiplication) >= mod)
        {
            multiplication %= mod;
            if (multiplication < 0)
                multiplication += mod;
        }
    }

    cout << multiplication;
    return 0;
}
