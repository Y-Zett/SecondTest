
#include <iostream>
#include <vector>
using namespace std;

void Print(vector<int> array) {
	cout << "[";
	for (int i = 0; i < array.size(); i++) {
		cout << array[i];
		if (i != array.size() - 1) {
			cout << ",";
		}
	}
	cout << "]" << endl;
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
	vector<vector<int>> array;
	vector<int> a = {1031,1021,1033};
	vector<int> checkerA(3, 0);
	vector<int> b = {1031*1021,1033};
	vector<int> checkerB(2, 0);
	vector<int> c = {1031,1021*1033};
	vector<int> checkerC(2, 0);
	vector<int> d = {1021,1031*1033};
	vector<int> checkerD(2, 0);
	vector<int> e = {1021*1031*1033,1};
	vector<int> checkerc(2, 0);
	array.push_back(a);
	array.push_back(b);
	array.push_back(c);
	array.push_back(d);
	array.push_back(e);
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < array.size(); i++) {
			for (int k = 0; k < array[i].size(); k++) {
				if (array[i][k] == sequense[j])
					array[i][k] = 1;
			}
		}
	}
		
	
	bool lastchecker = false;
	vector<int> truechecker(2, 1);
	vector<int> onemorechecker(3, 1);

	for (int i = 0; i < array.size(); i++) {
		if (truechecker == array[i]) {
			cout << "YES";
			lastchecker = true;
			break;
		}
		if (i == 0)
			if (array[i] == onemorechecker) {
				cout << "YES";
				lastchecker = true;
				break;
			}
	}
	
	if (lastchecker == false)
		cout << "NO";
	


	return 0;
}
