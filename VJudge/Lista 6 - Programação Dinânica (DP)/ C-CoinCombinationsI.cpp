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

    ll n, x;
    cin >> n >> x;

    v64 coin(n);

    forn(i, 0, n)
        cin >> coin[i];

    v64 dp(x + 1, 0);
    dp[0] = 1;

    fornme(s, 1, x)
    {
        for (ll c : coin)
        {
            if (c <= s)
            {
                dp[s] += dp[s - c];
                if (dp[s] >= MOD)
                    dp[s] -= MOD;
            }
        }
    }

    cout << dp[x] << ln;

    return 0;
}