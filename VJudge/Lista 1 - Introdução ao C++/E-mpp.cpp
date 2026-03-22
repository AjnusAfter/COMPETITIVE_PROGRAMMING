#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

int main()
{
    string s;
    cin >> s;
    map<char, int> frequencia;

    for (char c : s)
    {
        frequencia[c]++;
    }

    vector<char> mais_freq;
    ll max_count = 0;

    for (auto &[k, v] : frequencia)
    {
        if (v > max_count)
        {
            max_count = v;
        }
    }

    for (auto &[k, v] : frequencia)
    {
        if (v == max_count)
        {
            mais_freq.push_back(k);
        }
    }

    for (char c : mais_freq)
    {
        s.erase(remove(s.begin(), s.end(), c), s.end());
    }

    cout << s << "\n";

    return 0;
}