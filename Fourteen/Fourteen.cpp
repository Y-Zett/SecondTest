#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const long long MAX_N = 100;
const long long mod = 1000000000 + 7;
long long N;

vector<vector<long long>> g(MAX_N, vector<long long>(MAX_N, 0));
vector<vector<long long>> r(MAX_N, vector<long long>(MAX_N, 0));

void mulg(vector<vector<long long>> a, vector<vector<long long>> b)
{
    for (long i = 0; i < N; ++i)
        for (long j = 0; j < N; ++j)
        {
            long long s = 0;
            for (long k = 0; k < N; ++k)
                s += (a[i][k] * b[k][j]) % mod;
            s %= mod;
            g[i][j] = s;
        }
}

void mulr(vector<vector<long long>> a, vector<vector<long long>> b)
{
    for (long long i = 0; i < N; ++i)
        for (long j = 0; j < N; ++j)
        {
            long long s = 0;
            for (long k = 0; k < N; ++k)
                s = (s + a[i][k] * b[k][j]) % mod;
            
            r[i][j] = s;
        }
}

int main()
{
    long M, U, V, P;
    cin >> N >> M >> U >> V >> P;
    U--;
    V--;

    for (long i = 0; i < M; i++)
    {
        long long A, B;
        cin >> A >> B;
        A--;
        B--;
        g[A][B] += (A == B) ? 2 : 1;
        g[B][A] += (A == B) ? 0 : 1;
    }

    // cout << endl;

    // for (long i = 0; i < N; i++)
    // {
    //     for (long j = 0; j < N; j++)
    //     {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    if (P % 2)
    {
        for (long j = 0; j < N; ++j)
            for (long k = 0; k < N; ++k)
                r[j][k] = g[j][k];
    }
    else
    {
        for (long j = 0; j < N; ++j)
            for (long k = 0; k < N; ++k)
                r[j][k] = (j == k) ? 1 : 0;
    }

    while (P /= 2)
    {

        mulg(g, g);
        if (P % 2)
            mulr(g, r);
    }
    // cout << endl;
    // for (long i = 0; i < N; i++)
    // {
    //     for (long j = 0; j < N; j++)
    //     {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << r[U][V];

    return 0;
}
