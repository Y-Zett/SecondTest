#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Print(vector<long> array) {
    cout << "[";
    for (int i = 0; i < array.size(); i++) {
        cout << array[i];
        if (i != array.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}
vector<long>Reverse(vector<long> array) {
    for (int i = 0; i < array.size() / 2; i++) {
        int tmp = array[i];
        array[i] = array[array.size() - 1 - i];
        array[array.size() - 1 - i] = tmp;
    }
    return array;
}
long Compare(long first, long second){
    if (second >= first)
        return second;
    else
        return first;
}
int main()
{
    long size;
    cin >> size;
    vector<long> sequense(size);
    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        sequense[i] = num;
    }
    sort(sequense.rbegin(),sequense.rend());
    sequense = Reverse(sequense);
    //Print(sequense);
    long max = Compare(sequense[sequense.size()-1]* sequense[sequense.size() - 2], sequense[0]* sequense[1]);

    /*
    long val = 0;
    for (int i = 0; i < size; i++) {
        int tmp = sequense[i];
        if (i <= size - 2) {
            for (int j = i + 1; j < size; j++) {
                val = tmp * sequense[j];
                if (max < val)
                    max = val;
            }
        }
    }*/
    cout<<max;
}