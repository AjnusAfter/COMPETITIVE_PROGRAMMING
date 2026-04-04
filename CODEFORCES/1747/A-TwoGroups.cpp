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

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll sum = 0;

        // cout << "sum: " << sum << ln;

        forn(i, 0, n)
        {
            ll x;
            cin >> x;
            // cout << "x: " << x << ln;
            // cout << "sum += x: " << sum << " += " << x << ln;
            sum += x;
            // cout << "sum: " << sum << ln;
        }

        cout /*<< "maior soma possível: " */ << abs(sum) << ln /* << ln*/;
    }

    return 0;
}