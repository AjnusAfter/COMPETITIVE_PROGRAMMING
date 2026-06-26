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

    ll n, q;
    cin >> n >> q;

    vector<string> grid(n + 1);
    vector<v64> pref(n + 1, v64(n + 1, 0));

    forn(i, 1, n + 1)
    {
        string s;
        cin >> s;
        grid[i] = " " + s;
    }

    forn(i, 1, n + 1)
    {
        forn(j, 1, n + 1)
        {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (grid[i][j] == '*');
        }
    }

    while (q--)
    {
        ll y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        ll ans = pref[y2][x2] - pref[y1 - 1][x2] - pref[y2][x1 - 1] + pref[y1 - 1][x1 - 1];

        cout << ans << ln;
    }

    return 0;
}