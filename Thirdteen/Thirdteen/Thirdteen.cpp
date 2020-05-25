#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

void Prlong(vector<long> array) {
    cout << "[";
    for (long i = 0; i < array.size(); i++) {
        cout << array[i];
        if (i != array.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

void VectorPrlong(vector<vector<long>> array) {
    for (long i = 0; i < array.size(); i++) {
        cout << i << " -> ";
        Prlong(array[i]);
    }
}


int main() {
    long M;
    long N;
    cin >> N >> M;
    long* checked = new long[N];
    for (long i = 0; i < N; i++) 
    {
        checked[i] = 0;
    }
    vector<long> num;
    vector<vector<long>> graph(N, num);
    for (long i = 0; i < M; i++) 
    {
        vector<long> in(2, 0);
        cin >> in[0] >> in[1];
        in[0] -= 1;
        in[1] -= 1;
        graph[in[0]].push_back(in[1]);
        graph[in[1]].push_back(in[0]);

    }
    long j = 0;
    long counter = 0;
    checked[0] = 1;
    for (long i = 0; i < N; i++) 
    {
        if (graph[j].empty() == false) 
        {
            for (long k = 0; k < graph[i].size(); k++) 
            {
                if (checked[graph[i][k]] == 0) 
                {
                    checked[graph[i][k]] = 1;
                    j = graph[i][k];
                    counter++;
                    break;
                }

            }
            
        }

    }

    for (int i = 0; i < N; i++)
    {
        if (checked[i] == 0)
        {
            
            if (graph[i].empty() == false) 
            {
                checked[i] = 1;
                counter++;
            }
        }
    }
    
    if (counter == N - 1) {
        cout << M - (N - 1);
    }
    else
        cout << "-1";
    
    delete[] checked;
    return 0;
}