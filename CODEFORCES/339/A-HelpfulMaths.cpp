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

    string s;
    cin >> s;

    vector<char> a;
    for (char c : s)
    {
        if (c != '+')
        {
            a.push_back(c);
        }
    }

    sort(a.begin(), a.end());

    forn(i, 0, a.size())
    {
        if (i)
        {
            cout << '+';
        }

        cout << a[i];
    }

    cout << ln;

    return 0;
}