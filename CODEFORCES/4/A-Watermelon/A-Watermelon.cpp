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

    ll w;
    cin >> w;

    if (w % 2 == 0 && w != 2)
    {
        cout << "YES" << ln;
    }
    else
    {
        cout << "NO" << ln;
    }
    return 0;
}