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

    ll upp_count = 0;
    ll low_count = 0;
    forn(i, 0, s.size())
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            upp_count++;
        else
            low_count++;
    }

    if (upp_count > low_count)
    {
        forn(i, 0, s.size())
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] -= 32;
            }
        }
    }
    else
    {
        forn(i, 0, s.size())
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] += 32;
            }
        }
    }

    cout << s << ln;

    return 0;
}