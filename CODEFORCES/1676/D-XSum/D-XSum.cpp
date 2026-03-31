#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie(0);
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

int main()
{
    _;

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        vector<v64> a(n, v64(m));
        v64 diag1(n + m + 5, 0), diag2(n + m + 5, 0);

        forn(i, 0, n)
        {
            forn(j, 0, m)
            {
                cin >> a[i][j];
                diag1[i - j + m] += a[i][j];
                diag2[i + j] += a[i][j];
            }
        }

        ll ans = 0;

        forn(i, 0, n)
        {
            forn(j, 0, m)
            {
                ll sum = diag1[i - j + m] + diag2[i + j] - a[i][j];
                ans = max(ans, sum);
            }
        }

        cout << ans << ln;
    }

    return 0;
}