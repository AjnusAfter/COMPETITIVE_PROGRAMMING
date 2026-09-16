#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

int main()
{
    _;

    unordered_map<string, string> mp;
    string line;

    // read dict
    while (getline(cin, line))
    {
        if (line.empty())
        {
            break;
        }

        stringstream ss(line);

        string english, foreign;
        ss >> english >> foreign;

        mp[foreign] = english;
    }

    // read msg words
    string word;
    while (getline(cin, word))
    {
        if (mp.count(word))
        {
            cout << mp[word] << ln;
        }

        else
        {
            cout << "eh" << ln;
        }
    }

    return 0;
}