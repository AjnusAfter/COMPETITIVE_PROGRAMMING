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

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        forn(i, 1, n + 1)
        {
            ll a = i;
            ll m = n + 2 * i - 1;
            ll b = n + 2 * i;

            cout << a << " " << m << " " << b;

            if (i != n)
            {
                cout << " ";
            }
        }

        cout << ln;
    }

    return 0;
}