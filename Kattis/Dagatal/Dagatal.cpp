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

    ll m;
    cin >> m;

    if (m < 8)
    {
        if (m % 2 == 1)
        {
            cout << 31 << ln;
        }
        else
        {
            cout << (m == 2 ? 28 : 30) << ln;
        }
    }
    else
    {
        if (m % 2 == 0)
        {
            cout << 31 << ln;
        }
        else
        {
            cout << 30 << ln;
        }
    }

    return 0;
}
