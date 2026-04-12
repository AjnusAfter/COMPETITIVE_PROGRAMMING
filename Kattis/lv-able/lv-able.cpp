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
    string s;
    // s.reserve(N);
    cin >> N >> s;

    forn(i, 0, N)
    {
        if (s[i] == 'l' && s[i + 1] == 'v')
        {
            cout << 0 << ln;
            return 0;
        }
    }

    bool has_l = 0;
    bool has_v = 0;

    for (char c : s)
    {
        if (c == 'l')
        {
            has_l = 1;
        }

        if (c == 'v')
        {
            has_v = 1;
        }
    }

    if (has_l || has_v)
    {
        cout << 1 << ln;
    }
    else
    {
        cout << 2 << ln;
    }

    return 0;
}