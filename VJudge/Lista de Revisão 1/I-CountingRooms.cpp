#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define _ ios::sync_with_stdio(0), cin.tie(0)
#define ln "\n"

void dfs(ll u, vector<v64> &g, v64 &vis)
{
    vis[u] = 1;
    for (ll v : g[u])
        if (!vis[v])
            dfs(v, g, vis);
}

int main()
{
    _;

    ll n, m;
    cin >> n >> m;

    /*
    forn(i, 0, n)
    {
        string s;
        cin >> s;
    */
    vector<string> grid(n);
    forn(i, 0, n) cin >> grid[i];

    vector<v64> g(n * m);
    v64 vis(n * m);

    forn(i, 0, n)
    {
        forn(j, 0, m)
        {
            if (grid[i][j] == '#')
                continue;

            ll u = i * m + j; // ID único pra cada célula no grid, agora nó no grafo

            // se tem chão em...
            // cima
            if (i > 0 && grid[i - 1][j] == '.')
                g[u].push_back((i - 1) * m + j);
            // esquerda
            if (j > 0 && grid[i][j - 1] == '.')
                g[u].push_back(i * m + j - 1);
            // baixo
            if (i + 1 < n && grid[i + 1][j] == '.')
                g[u].push_back((i + 1) * m + j);
            // direita
            if (j + 1 < m && grid[i][j + 1] == '.')
                g[u].push_back(i * m + j + 1);
        }
    }

    // à partir do grid, grafo montado. vamos à resposta

    ll ans = 0;

    forn(i, 0, n)
    {
        forn(j, 0, m)
        {
            ll u = i * m + j;

            if (grid[i][j] == '.' && !vis[u])
            {
                ans++;
                dfs(u, g, vis);
            }
        }
    }

    cout << ans << ln;

    /*
    g.resize(n);
    vis.assign(n + 1, 0);

    forn(i, 0, n) cin >> g[i]; */

    /*
    bool is_floor, room_open;
    ll rooms = 0;

    for (char c : s)
    {
        if (c == '.')
        {
            //is_floor = true;
            room_open = true;
        }

        if (room_open && c == '#')
        {
            //is_floor = false;
            rooms++;
            room_open = false;
        }
    }
        */
    //}

    return 0;
}
