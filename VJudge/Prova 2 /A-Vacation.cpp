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

    ll N;
    cin >> N;

    v64 A(N + 1), B(N + 1), C(N + 1);

    forn(i, 1, N + 1)
    {
        cin >> A[i] >> B[i] >> C[i];
    }

    vector<v64> dp(N + 1, v64(3, 0));

    dp[1][0] = A[1];
    dp[1][1] = B[1];
    dp[1][2] = C[1];

    forn(i, 2, N + 1)
    {
        dp[i][0] = A[i] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = B[i] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = C[i] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << max({dp[N][0], dp[N][1], dp[N][2]}) << ln;
}