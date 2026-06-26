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

const ll MOD = 1000000007;

ll modpow(ll base, ll exp)
{
    ll res = 1;

    while (exp)
    {
        if (exp & 1)
            res = res * base % MOD;

        base = base * base % MOD;
        exp >>= 1;
    }

    return res;
}

int main()
{
    _;

    ll W, H;
    cin >> W >> H;

    ll n = W - 1 + H - 1;
    ll k = W - 1;

    v64 fact(n + 1, 1);

    forn(i, 2, n + 1)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }

    ll inv_K = modpow(fact[k], MOD - 2);
    ll inv_NK = modpow(fact[n - k], MOD - 2);

    ll ans = fact[n] * inv_K % MOD * inv_NK % MOD;

    cout << ans << ln;

    return 0;
}