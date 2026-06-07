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

int main()
{
    _;

    ll N;
    cin >> N;

    v64 h(N + 1);

    fornme(i, 1, N)
    {
        cin >> h[i];
    }

    v64 dp(N + 1);

    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);

    fornme(i, 3, N)
    {
        dp[i] = min(
            dp[i - 1] + abs(h[i] - h[i - 1]),
            dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N] << ln;

    return 0;
}