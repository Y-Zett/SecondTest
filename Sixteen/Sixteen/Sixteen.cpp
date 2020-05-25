#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int FromArrayToNum(vector<int> array) { 
    int val = 0;
    for (int i = 0; i < array.size();i++) {
        val += array[i] * powf(10, array.size() - 1 - i);
    }
    return val;
}

vector<int> Reverse(vector<int> array) {
    for (int i = 0; i < array.size() / 2; i++) {
        int tmp = array[i];
        array[i] = array[array.size() - 1 - i];
        array[array.size() - 1 - i] = tmp;
    }
    return array;
}

vector<int> FromIntToArray(int num) {
    vector<int> array;
    while (num!=0) {
        array.push_back(num%10);
        num /= 10;
    }
    array = Reverse(array);
    return array;
}

void Print(vector<int> array) {
    cout << "[";
    for (int i = 0; i < array.size();i++) {
        cout << array[i];
        if (i != array.size() - 1) {
            cout << ",";
        }
    }
    cout << "]"<<endl;
}

int Permutations(vector<int> array,long number){
    long min = 1000000;
    long val = 0;
    sort(array.rbegin(), array.rend());
    do {
        val = FromArrayToNum(array);
        if (val > number&&min>val) {
            min = val;
        }
    } while (next_permutation(array.rbegin(), array.rend()));
    if (min != 1000000)
        return min;
    else
        return -1;
}

int main()
{
    long num;
    cin >> num;
    vector<int> array;
    array = FromIntToArray(num);
    cout << Permutations(array, num);
    return 0;
}