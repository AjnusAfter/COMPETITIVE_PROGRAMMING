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

    ll n, h;
    cin >> n >> h;

    ll w = 0;
    forn(i, 0, n)
    {
        ll a;
        cin >> a;

        if (a > h)
            w += 2;
        else
            w++;
    }

    cout << w << ln;

    return 0;
}