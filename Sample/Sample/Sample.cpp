#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int Example()
{
	string s; // входная строка
	cin >> s;
	int n = (int)s.length();

	// считаем все степени p
	const int p = 31;
	vector<long long> p_pow(s.length());
	p_pow[0] = 1;
	for (size_t i = 1; i < p_pow.size(); ++i)
		p_pow[i] = p_pow[i - 1] * p;

	// считаем хэши от всех префиксов
	vector<long long> h(s.length());
	for (size_t i = 0; i < s.length(); ++i)
	{
		h[i] = (s[i] - 'a' + 1) * p_pow[i];
		if (i)  {h[i] += h[i - 1]; cout << i << endl;}
	}

	int result = 0;

	// перебираем длину подстроки
	for (int l = 1; l <= n; ++l)
	{
		// ищем ответ для текущей длины

		// получаем хэши для всех подстрок длины l
		vector<long long> hs(n - l + 1);
		for (int i = 0; i < n - l + 1; ++i)
		{
			long long cur_h = h[i + l - 1];
			if (i)  cur_h -= h[i - 1];
			// приводим все хэши к одной степени
			cur_h *= p_pow[n - i - 1];
			hs[i] = cur_h;
		}

		// считаем количество различных хэшей
		sort(hs.begin(), hs.end());
		hs.erase(unique(hs.begin(), hs.end()), hs.end());
		result += (int)hs.size();
	}

	cout << result;
	return 0;
}





int main(){
	Example();
	return 0;
}