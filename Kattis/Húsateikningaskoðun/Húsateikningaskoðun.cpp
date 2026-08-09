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

    ll h, w;
    cin >> h >> w;

    ll pl_cnt = 0;
    ll mn_cnt = 0;

    vector<vector<char>> grid(h + 2, vector<char>(w + 2, '#'));

    forn(i, 1, h + 1)
    {
        forn(j, 1, w + 1)
        {
            cin >> grid[i][j];

            if (grid[i][j] == '+')
            {
                pl_cnt++;
            }
            else
            {
                mn_cnt++;
            }
        }
    }

    bool neibb = false;

    forn(i, 1, h + 1)
    {
        forn(j, 1, w + 1)
        {
            if ((grid[i - 1][j] != grid[i][j] && grid[i + 1][j] != grid[i][j]) &&
                (grid[i][j - 1] != grid[i][j] && grid[i][j + 1] != grid[i][j]) &&
                (pl_cnt != 1 && mn_cnt != 1))
            {
                neibb = true;
            }
        }
    }

    ll min_h2 = h + 1;
    ll max_h2 = 0;
    ll min_w2 = w + 1;
    ll max_w2 = 0;

    forn(i, 1, h + 1)
    {
        forn(j, 1, w + 1)
        {
            if (grid[i][j] == '-')
            {
                min_h2 = min(min_h2, i);
                max_h2 = max(max_h2, i);
                min_w2 = min(min_w2, j);
                max_w2 = max(max_w2, j);
            }
        }
    }

    forn(i, 1, h + 1)
    {
        forn(j, 1, w + 1)
        {
            bool dentro = (i >= min_h2 && i <= max_h2 && j >= min_w2 && j <= max_w2);

            if (dentro)
            {
                if (grid[i][j] != '-')
                {
                    neibb = true;
                }
            }
            else
            {
                if (grid[i][j] != '+')
                {
                    neibb = true;
                }
            }
        }
    }

    if (neibb)
    {
        cout << "Neibb" << ln;
        return 0;
    }

    ll h1 = h;
    ll w1 = w;
    ll h2 = max_h2 - min_h2 + 1;
    ll w2 = max_w2 - min_w2 + 1;

    cout << h1 << " " << w1 << " " << h2 << " " << w2 << ln;

    return 0;
}