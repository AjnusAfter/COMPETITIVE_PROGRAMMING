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

ll mul_mod(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;

    while (b > 0)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }

    return res;
}

ll mod_pow(ll base, ll exp, ll mod)
{
    ll res = 1;
    base %= mod;

    while (exp > 0)
    {
        if (exp & 1)
            res = mul_mod(res, base, mod);
        base = mul_mod(base, base, mod);
        exp >>= 1;
    }

    return res;
}

int main()
{
    _;

    ll a, b, n;
    cin >> a >> b >> n;

    ll inv_b = mod_pow(b, n - 2, n);
    ll ans = mul_mod(a, inv_b, n);

    cout << ans << ln;

    return 0;
}