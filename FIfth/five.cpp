#include <iostream>
#include <vector>
#include <utility>
using namespace std;
const long MAX_N = 10e5;
const long MAX_M = 10e6;
const int one = 1;
long M;
long N;

vector<pair<int, int>> graph[MAX_N];
long radius[MAX_N];
void Step(long k)
{
    for (long i = 0; i < graph[k].size(); i++)
    {
    }
}

int main()
{
    long a, b;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int input[3];
        cin >> input[0] >> input[1] >> input[2];
        input[0]--;
        input[1]--;

        graph[input[0]].push_back(make_pair(input[1], input[2]));
        graph[input[1]].push_back(make_pair(input[0], input[2]));
    }

    cin >> a >> b;
    a--;
    b--;
    for (long i = 0; i < N; i++)
    {
        radius[i] = 10000;
    }
    radius[a] = 0;
    return 0;
}
