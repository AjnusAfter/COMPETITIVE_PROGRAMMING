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

    string s, t;
    cin >> s >> t;

    forn(i, 0, t.size())
    {
        if (s[i] != t[t.size() - 1 - i] || s.size() != t.size())
        {
            cout << "NO" << ln;
            return 0;
        }
    }
    cout << "YES" << ln;

    return 0;
}
