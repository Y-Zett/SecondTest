#include <iostream>
#include <vector>
using namespace std;
const long MAX_N = 10000;
long M;
long N;
bool checked[MAX_N];
vector<long> graph[MAX_N];
void StepIn(long v)
{
    checked[v] = true;
    for (int i = 0; i < graph[v].size(); i++)
    {   
        long to = graph[v][i];
        if (checked[to] == 0)
            StepIn(to);
    }
}

int main()
{
    cin >> N >> M;
    for (long i = 0; i < M; i++) 
    {
        vector<long> in(2, 0);
        cin >> in[0] >> in[1];
        in[0] -= 1;
        in[1] -= 1;
        graph[in[0]].push_back(in[1]);
        graph[in[1]].push_back(in[0]);

    }

    int component = 0;
    for (int i = 0; i < N; i++)
    {
        if(!checked[i])
        {
            StepIn(i);
            component ++;
        }
    }
    cout << component - 1;

    return 0;
}
