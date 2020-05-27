#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const long long MAX_N = 100;
const long long mod = 10e9 + 7;
long long N;


vector<vector<long long>> c (N, vector<long long>(N, 0));



void mul(vector<vector<long long>> a, vector<vector<long long>> b, vector<vector<long long>> &c)
{
    vector<long long> d[MAX_N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            long s = 0;
            for (int k = 0; k < N; ++k)
                s += a[i][k] * b[k][j];
            ((c == a || c == b) ? d[i][j] : c[i][j]) = s;
        }
    if (c == a || c == b)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                c[i][j] = d[i][j];
}

int main()
{
    long M, U, V, P;
    cin >> M >> N >> U >> V >> P;

    for (int i = 0; i < M; i++)
    {
        long long A, B;
        cin >> A >> B;
        A--;
        B--;
        с[A][B] = 1;
    }

    // for (long i = 0; i < N; i++)
    // {
    //     for (long j = 0; j < N; j++)
    //     {
    //         cout << с[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    if (P % 2)
    {
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                r[j][k] = с[j][k];
    }
    else
    {
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                r[j][k] = (j == k) ? 1 : 0;
    }

    while (P /= 2)
    {
        mul(с, с, с);
        if (p % 2)
            mul(i, r, r);
    }

    return 0;
}
