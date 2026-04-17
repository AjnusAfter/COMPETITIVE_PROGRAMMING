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

int main()
{
    _;

    ll N;
    cin >> N;

    v64 a(N);

    forn(i, 0, N)
    {
        cin >> a[i];
    }

    ll ans = 0;
    ll pow_2 = 1;

    forn(bit, 0, 60)
    {
        ll count_1 = 0;

        forn(i, 0, N)
        {
            if ((a[i] >> bit) & 1LL)
            {
                count_1++;
            }
        }

        ll cnt0 = N - count_1;

        ll contrib = (count_1 % MOD) * (cnt0 % MOD) % MOD;
        contrib = (contrib * pow_2) % MOD;

        ans = (ans + contrib) % MOD;
        pow_2 = (pow_2 * 2) % MOD;
    }
    cout << ans << ln;

    return 0;
}