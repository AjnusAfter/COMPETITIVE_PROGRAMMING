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

const ll MOD = 1e9 + 7;

int main()
{
    _;

    ll T;
    cin >> T;

    while (T--)
    {
        ll N, M;
        cin >> N >> M;

        // calcula (2^N) % MOD | cmath pow() perde precisão; estoura; não funciona com módulo; inutilizável para Prog Comp
        ll base = 2;
        ll exp = N;
        ll pow2 = 1;

        while (exp)
        {
            if (exp & 1)
            {
                pow2 = (pow2 * base) % MOD;
            }

            base = (base * base) % MOD;
            exp >>= 1;
        }

        ll x = (pow2 - 1 + MOD) % MOD; // (2^N-1) % MOD;

        // calcula (x^M) % MOD
        base = x;
        exp = M;

        ll ans = 1;

        while (exp)
        {
            if (exp & 1)
                ans = (ans * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }

        cout << ans << ln;
    }

    return 0;
}