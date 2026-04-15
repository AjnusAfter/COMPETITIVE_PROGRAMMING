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
        ll a = 0, b = 0;

        forn(i, 1, n + 1)
        {
            ll temp = n ^ i;
            if (i <= temp && temp <= n)
            {
                a = i;
                b = temp;
                break;
            }
        }

        if (a != 0 && b != 0)
            cout << a << " " << b << ln;
        else
            cout << -1 << ln;
    }
    return 0;
}