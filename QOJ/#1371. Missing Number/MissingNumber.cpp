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

    ll n;
    string s;
    cin >> n >> s;

    forn(missing, 1, n + 1)
    {
        string t = "";
        forn(i, 1, n + 1)
        {
            if (i != missing)
                t += to_string(i);
        }
        if (t == s)
        {
            cout << missing << ln;
            return 0;
        }
    }

    return 0;
}