﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

void Print(vector<pair<int, int >> array) {
    cout << "[";
    for (long i = 0; i < array.size(); i++) {
        cout << array[i].first << " (" << array[i].second << ") ";
        if (i != array.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void VectorPrint(vector<vector<pair<int , int>>> array) {
    for (long i = 0; i < array.size(); i++) {
        cout << i << " -> ";
        Print(array[i]);
    }
}

int main()
{
    long N;
    cin >> N;
    long M;
    cin >> M;
    vector<vector <pair<int, int>>> graph(N);

    for (int i = 0; i < M; i++) {
        int input[3];
        cin >> input[0] >> input[1] >> input[2];
        input[0]--;
        input[1]--;
        
        graph[input[0]].push_back(make_pair(input [1], input[2]));
        graph[input[1]].push_back(make_pair(input[0], input[2]));
        
    }
    
    int input[2];
    cin >> input[0] >> input[1];
    input[0]--;
    input[1]--;
    vector<int> d(N,1000000);
    vector<int> v(N, 1);
    d[input[0]] = 0;
    int minindex, min, temp;
    do {
        minindex = 1000000;
        min = 1000000;
        for (int i = 0; i < N; i++) {
            if ((v[i] == 1) && (d[i] < min)) {
                min = d[i];
                minindex = i;
            }
        }
        if (minindex != 1000000) {
            for (int i = 0; i < graph[minindex].size(); i++) {
                if (graph[minindex][i].second > 0) {
                    temp = min + graph[minindex][i].second;
                    if (temp < d[graph[minindex][i].first]) {
                        d[graph[minindex][i].first] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
    } while (minindex < 1000000);
    cout << d[input[1]] << endl;
    //VectorPrint(graph);
    return 0; 
}