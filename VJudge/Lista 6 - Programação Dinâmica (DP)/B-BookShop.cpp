#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define fornm(i, s, e) for (ll i = (s); i >= (e); i--)
#define ln "\n"

int main()
{
    _;

    ll n, x;
    cin >> n >> x;

    v64 h(n), s(n);

    forn(i, 0, n)
        cin >>h[i];

    forn(i, 0, n)
            cin >> s[i];

    v64 dp(x + 1, 0);

    forn(i, 0, n)
    {
        fornm(j, x, h[i])
        {
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }

    cout << dp[x] << ln;

    return 0;
}