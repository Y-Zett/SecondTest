#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    long N;
    cin >> N;
    long M;
    cin >> M;
    vector<vector<pair<int, int>>> graph(N);

    for (int i = 0; i < M; i++)
    {
        int input[3];
        cin >> input[0] >> input[1] >> input[2];
        input[0]--;
        input[1]--;

        graph[input[0]].push_back(make_pair(input[1], input[2]));
        graph[input[1]].push_back(make_pair(input[0], input[2]));
    }

    int input[2];
    cin >> input[0] >> input[1];
    input[0]--;
    input[1]--;
    vector<long> d(N, LONG_MAX);
    vector<long> v(N, 0);
    d[input[0]] = 0;
    int node = input[0];
    int minindex;
    for (int i = 0; i < N; i++)
    {
        v[node] = true;

        for (int j = 0; j < graph[node].size(); j++)
        {
            long sidepoint = graph[node][j].first;
            long weight = graph[node][j].second;

            if (d[node] + weight < d[sidepoint])
            {
                d[sidepoint] = d[node] + weight;
            }
        }

        long minValue = LONG_MAX;
        int minindex = 0;
        for (int i = 0; i < N; i++)
        {
            if (v[i])
                continue;
            if (d[i] < minValue)
            {
                minValue = d[i];
                minindex = i;
            }
        }
        node = minindex;
    }
    cout << d[input[1]];
    return 0;
}