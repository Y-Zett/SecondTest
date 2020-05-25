#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
long long const MAX_N = 100000;
long long MAX_A = 2000000000;
long long N;
long long K;

int main()
{
    long long modul = 1e9 + 7;
    cin >> N;
    cin >> K;
    vector<pair<long, int>> seq(N);
    vector<long> kp;
    vector<long> km;
    bool havepositive = false;
    for (long long i = 0; i < N; ++i)
    {
        cin >> seq[i].first;
        if (seq[i].first > 0)
            seq[i].second = 0;
        else
            seq[i].second = 1;

        if (seq[i].first > 0 && !havepositive)
            havepositive = true;
    }

    for (size_t i = 0; i < seq.size(); ++i)
    {
        if (seq[i].second == 1)
            seq[i].first *= -1;
    }

    long long t = seq.size() - 1;
    sort(seq.begin(), seq.end());
    for (long long i = 0; i < K; ++i)
    {
        if (!seq[t].second)
            kp.push_back(seq[t].first);
        else
            km.push_back(seq[t].first);

        t--;
    }

    if (km.size() % 2 == 1)
    {
        if (kp.empty())
        {
            if (havepositive)
            {
                long long maxp = 0;
                km.pop_back();
                for (long long i = t; i >= 0; --i)
                {
                    if (seq[i].first > maxp && !seq[i].second)
                        maxp = seq[i].first;
                }

                kp.push_back(maxp);
            }
            else
            {
                km.clear();
                for (long long i = 0; i < K; i++)
                    km.push_back(seq[i].first);
                km[0] *= -1;
            }
        }
        else
        {
            long long maxp = 0;
            long long maxm = 0;
            long long m;
            long long p;
            if (!kp.empty())
            {
                p = kp[kp.size() - 1];
                kp.pop_back();
            }
            else
                p = 0;

            if (!km.empty())
            {
                m = km[km.size() - 1];
                km.pop_back();
            }
            else
                m = 0;

            for (long long i = t; i >= 0; i--)
            {
                if (!seq[i].second)
                {
                    if (seq[i].first > maxp)
                        maxp = seq[i].first;
                }
                else
                {
                    if (seq[i].first > maxm)
                        maxm = seq[i].first;
                }
            }

            if (maxm * m >= maxp * p)
            {
                km.push_back(m);
                km.push_back(maxm);
            }
            else
            {
                kp.push_back(p);
                kp.push_back(maxp);
            }
        }
    }

    long long multiply = 1;
    for (long long el : kp)
        multiply *= el;

    for (long long el : km)
        multiply *= el;
    
    if (abs(multiply) < modul)
    {
        multiply %= modul;
        if (multiply < 0)
            multiply += modul;   
    }

    while (abs(multiply) >= modul)
    {
        multiply %= modul;
        if (multiply < 0)
            multiply += modul;
    }

    cout << multiply;
    return 0;
}