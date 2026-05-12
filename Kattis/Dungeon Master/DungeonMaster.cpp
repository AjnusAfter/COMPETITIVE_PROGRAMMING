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

struct Node
{
    ll z, x, y, dist;
};

int main()
{
    _;

    ll L, R, C;

    while (cin >> L >> R >> C)
    {
        if (L == 0 && R == 0 && C == 0)
            break;

        vector<vector<string>> dungeon(L, vector<string>(R));

        ll sz, sx, sy;

        forn(l, 0, L)
        {
            forn(r, 0, R)
            {
                cin >> dungeon[l][r];

                forn(c, 0, C)
                {
                    if (dungeon[l][r][c] == 'S')
                    {
                        sz = l;
                        sx = r;
                        sy = c;
                    }
                }
            }
        }

        vector<vector<vector<bool>>> vis(
            L,
            vector<vector<bool>>(R, vector<bool>(C, false)));

        queue<Node> q;

        q.push({sz, sx, sy, 0});
        vis[sz][sx][sy] = true;

        ll dz[] = {1, -1, 0, 0, 0, 0};
        ll dx[] = {0, 0, 1, -1, 0, 0};
        ll dy[] = {0, 0, 0, 0, 1, -1};

        bool escaped = false;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            ll z = cur.z;
            ll x = cur.x;
            ll y = cur.y;
            ll dist = cur.dist;

            if (dungeon[z][x][y] == 'E')
            {
                cout << "Escaped in " << dist << " minute(s)." << ln;
                escaped = true;
                break;
            }

            forn(i, 0, 6)
            {
                ll nz = z + dz[i];
                ll nx = x + dx[i];
                ll ny = y + dy[i];

                if (nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C)
                    continue;

                if (vis[nz][nx][ny])
                    continue;

                if (dungeon[nz][nx][ny] == '#')
                    continue;

                vis[nz][nx][ny] = true;
                q.push({nz, nx, ny, dist + 1});
            }
        }

        if (!escaped)
            cout << "Trapped!" << ln;
    }

    return 0;
}