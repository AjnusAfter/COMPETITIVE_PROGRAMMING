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

    ll LOG = 0;
    while ((1LL << LOG) <= n)
        LOG++;

    vector<v64> up(n + 1, v64(LOG, 0));

    forn(i, 2, n + 1)
    {
        cin >> up[i][0];
    }

    forn(j, 1, LOG)
    {
        forn(i, 1, n + 1)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }

    while (q--)
    {
        ll x, k;
        cin >> x >> k;

        forn(j, 0, LOG)
        {
            if (k & (1LL << j))
            {
                x = up[x][j];
                if (x == 0)
                    break;
            }
        }

        cout << (x == 0 ? -1 : x) << ln;
    }

    return 0;
}