#include <iostream>
#include <vector>
#include <climits>

using namespace std;
const long MAX_N = 10e5;

int main()
{
    // int m, n;
    // int data[3];
    // int begin, end;

    // cin >> n;
    // cin >> m;

    // vector<vector<pair<int, int>>> graph(n);

    // for (int i = 0; i < m; i++)
    // {
    //     cin >> data[0] >> data[1] >> data[2];
    //     data[0] -= 1;
    //     data[1] -= 1;

    //     graph[data[0]].push_back(make_pair(data[1], data[2]));
    //     graph[data[1]].push_back(make_pair(data[0], data[2]));
    // }

    // cin >> begin;
    // cin >> end;

    // begin--;
    // end--;

    // long *nodeValue = new long[n]{};
    // bool *visited = new bool[n]{};
    // for (int i = 0; i < n; i++)
    // {
    //     nodeValue[i] = LONG_MAX;
    // }

    // nodeValue[begin] = 0;
    // int fixedNode = begin;
    // for (int i = 0; i < n; i++)
    // {
    //     //cout << "fixedNode = " << fixedNode << endl;
    //     visited[fixedNode] = true;

    //     for (int j = 0; j < graph[fixedNode].size(); j++)
    //     {
    //         long neighbour = graph[fixedNode][j].first;
    //         long weight = graph[fixedNode][j].second;

    //         if (nodeValue[fixedNode] + weight < nodeValue[neighbour])
    //         {
    //             nodeValue[neighbour] = nodeValue[fixedNode] + weight;
    //         }
    //     }

    //     long minValue = LONG_MAX;
    //     int minIndex = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (visited[i])
    //         {
    //             continue;
    //         }

    //         if (nodeValue[i] < minValue)
    //         {
    //             minValue = nodeValue[i];
    //             minIndex = i;
    //         }
    //     }
    //     fixedNode = minIndex;
    // }

    // cout << nodeValue[end];

    return 0;
}
