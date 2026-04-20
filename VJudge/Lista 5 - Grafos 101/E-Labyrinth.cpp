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

bool bfs(vector<string> &g, vector<v64> &vis,
         vector<vector<p64>> &par, vector<vector<char>> &step,
         p64 A, p64 B)
{
    ll n = g.size(), m = g[0].size();

    v64 dx = {-1, 1, 0, 0};
    v64 dy = {0, 0, -1, 1};
    vector<char> dir = {'U', 'D', 'L', 'R'};

    queue<p64> q;
    q.push(A);
    vis[A.first][A.second] = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (p64{x, y} == B)
            return true;

        forn(k, 0, 4)
        {
            ll nx = x + dx[k];
            ll ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (vis[nx][ny])
                continue;
            if (g[nx][ny] == '#')
                continue;

            vis[nx][ny] = 1;
            par[nx][ny] = {x, y};
            step[nx][ny] = dir[k];
            q.push({nx, ny});
        }
    }

    return false;
}

int main()
{
    _;
    ll n, m;
    cin >> n >> m;

    vector<string> g(n);
    forn(i, 0, n)
    {
        cin >> g[i];
    }

    p64 A, B;
    forn(i, 0, n)
    {
        forn(j, 0, m)
        {
            if (g[i][j] == 'A')
            {
                A = {i, j};
            }
            if (g[i][j] == 'B')
            {
                B = {i, j};
            }
        }
    }

    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    vector<vector<p64>> par(n, vector<p64>(m, {-1, -1}));
    vector<vector<char>> step(n, vector<char>(m));

    if (!bfs(g, vis, par, step, A, B))
    {
        cout << "NO" << ln;
        return 0;
    }

    string path;
    p64 cur = B;

    while (cur != A)
    {
        path.push_back(step[cur.first][cur.second]);
        cur = par[cur.first][cur.second];
    }

    reverse(path.begin(), path.end());

    cout << "YES" << ln;
    cout << path.size() << ln;
    cout << path << ln;

    return 0;
}