#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie()
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

int main()
{
    _;

    const ll INF = (1LL << 60);

    ll n, m, q;
    while (cin >> n >> m >> q)
    {
        if (n == 0 && m == 0 && q == 0)
            break;

        vector<v64> dist(n, v64(n, INF));
        vector<vector<bool>> neg(n, vector<bool>(n, false));

        forn(i, 0, n)
            dist[i][i] = 0;

        forn(i, 0, m)
        {
            ll u, v, w;
            cin >> u >> v >> w;

            dist[u][v] = min(dist[u][v], w);
        }

        forn(k, 0, n)
        {
            forn(i, 0, n)
            {
                if (dist[i][k] == INF)
                    continue;

                forn(j, 0, n)
                {
                    if (dist[k][j] == INF)
                        continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        forn(k, 0, n)
        {
            if (dist[k][k] < 0)
            {
                forn(i, 0, n)
                {
                    if (dist[i][k] == INF)
                        continue;

                    forn(j, 0, n)
                    {
                        if (dist[k][j] == INF)
                            continue;

                        neg[i][j] = true;
                    }
                }
            }
        }

        forn(i, 0, q)
        {
            ll u, v;
            cin >> u >> v;

            if (neg[u][v])
                cout << "-Infinity" << ln;
            else if (dist[u][v] == INF)
                cout << "Impossible" << ln;
            else
                cout << dist[u][v] << ln;
        }

        cout << ln;
    }

    return 0;
}