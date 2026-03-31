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

        ll sum = 0;
        ll mx = 0;
        ll ans = 0;

        forn(i, 0, n)
        {
            ll x;
            cin >> x;
            sum += x;
            mx = max(mx, x);

            if (2 * mx == sum)
            {
                ans++;
            }
        }

        cout << ans << ln;
    }

    return 0;
}