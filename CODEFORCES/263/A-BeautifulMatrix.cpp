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

    ll i_pos, j_pos;

    vector<v64> mat(5, v64(5, 0));

    forn(i, 0, 5)
    {
        forn(j, 0, 5)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 1)
            {
                i_pos = i + 1;
                j_pos = j + 1;
            }
        }
    }

    // cout << i_pos << ln;
    // cout << j_pos << ln;

    cout << abs(3 - i_pos) + abs(3 - j_pos) << ln;

    return 0;
}