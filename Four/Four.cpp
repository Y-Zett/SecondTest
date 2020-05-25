#include <iostream>
#include <vector>
#include <utility>
using namespace std;
const long MAX_N = 100;
long M;
long N;

bool checkmate[MAX_N][MAX_N];
int way[MAX_N][MAX_N];

void Step(long x, long y, long stepcounter)
{
    stepcounter += 1;
    if (!checkmate[x][y])
        checkmate[x][y] = true;

    way[x][y] = stepcounter;
    

    if (x - 2 >= 0)
    {
        if (y + 1 < M)
        {
            if (way[x - 2][y + 1] > stepcounter + 1)
                Step(x - 2, y + 1, stepcounter);
        }

        if (y - 1 >= 0)
        {
            if (way[x - 2][y - 1] > stepcounter + 1)
                Step(x - 2, y - 1, stepcounter);
        }
    }

    if (x + 2 < N)
    {
        if (y + 1 < M)
        {
            if (way[x + 2][y + 1] > stepcounter + 1)
                Step(x + 2, y + 1, stepcounter);
        }

        if (y - 1 >= 0)
        {
            if (way[x + 2][y - 1] > stepcounter + 1)
                Step(x + 2, y - 1, stepcounter);
        }
    }

    if (y - 2 >= 0)
    {
        if (x + 1 < N)
        {
            if (way[x + 1][y - 2] > stepcounter + 1)
                Step(x + 1, y - 2, stepcounter);
        }

        if (x - 1 >= 0)
        {
            if (way[x - 1][y - 2] > stepcounter + 1)
                Step(x - 1, y - 2, stepcounter);
        }
    }

    if (y + 2 < M)
    {
        if (x + 1 < N)
        {
            if (way[x + 1][y + 2] > stepcounter + 1)
                Step(x + 1, y + 2, stepcounter);
        }

        if (x - 1 >= 0)
        {
            if (way[x - 1][y + 2] > stepcounter + 1)
                Step(x - 1, y + 2, stepcounter);
        }
    }

}

int main()
{
    long korx = 0;
    long kory = 0;
    long stepcounter = -1;
    cin >> N >> M >> korx >> kory;
    korx--;
    kory--;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            way[i][j] = 100000;
        }
    }

    Step(0, 0, stepcounter);

    if (checkmate[korx][kory])
        cout << way[korx][kory];
    else
        cout << "NEVAR";
    // cout << endl;

    // for (int i = N - 1; i >= 0; i--)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << way[i][j] << "| ";
    //     }

    //     cout << endl;
    // }

    return 0;
}
