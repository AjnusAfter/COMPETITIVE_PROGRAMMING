#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define fornme(i, s, e) for (ll i = (s); i <= (e); i++)
#define ln "\n"

ll MOD = 1e9 + 7;

int main()
{
    _;

    ll n;
    cin >> n;

    v64 dp(n + 1, 0);

    dp[0] = 1;

    fornme(i, 1, n)
    {
        fornme(d, 1, 6)
        {
            if (i - d >= 0)
            {
                dp[i] = (dp[i] + dp[i - d]) % MOD;
            }
        }
    }

    cout << dp[n] << ln;

    return 0;
}