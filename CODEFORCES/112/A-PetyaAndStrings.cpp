#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie()
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

int main()
{
    _;

    string s1, s2;
    cin >> s1 >> s2;

    for (char &c : s1)
        c = tolower(c);
    for (char &c : s2)
        c = tolower(c);

    if (s1 < s2)
    {
        cout << -1 << ln;
    }

    else if (s1 > s2)
    {
        cout << 1 << ln;
    }

    else
    {
        cout << 0 << ln;
    }

    return 0;
}