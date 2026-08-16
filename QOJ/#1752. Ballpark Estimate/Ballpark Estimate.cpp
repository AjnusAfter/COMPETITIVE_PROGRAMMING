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

    ll n;
    cin >> n;

    if (n < 10)
    {
        cout << n << ln;
        return 0;
    }

    ll base = 1;
    while (base * 10 <= n)
    {
        base *= 10;
    }

    ll pot_low = (n / base) * base;
    ll pot_high = pot_low + base;

    ll ans;
    n - pot_low < pot_high - n ? ans = pot_low : ans = pot_high;

    cout << ans << ln;
    return 0;
}
