#include <iostream>
#include <vector>
#include <utility>
using namespace std;
const long MAX_N = 10e5;
const long MAX_M = 10e6;

vector<pair<int, int>> graph[MAX_N];
long radius[MAX_N];
void Step(long k, long way)
{
    radius[k] = way;
    for (long i = 0; i < graph[k].size(); i++)
    {
        if (radius[graph[k][i].first] > way + graph[k][i].second)
        {
            Step(graph[k][i].first, way + graph[k][i].second);
        }
    }
}

int main()
{
    long M;
    long N;
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

    Step(a, 0);
    cout << radius[b];
    return 0;
}
