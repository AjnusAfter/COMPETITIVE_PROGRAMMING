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

    ll y;
    cin >> y;

    y++;
    string s = to_string(y);
    
    while (s[0] == s[1] || s[0] == s[2] || s[0] == s[3] || s[0] == s[4] || s[1] == s[2] || s[1] == s[3] || s[1] == s[4] || s[2] == s[3] || s[2] == s[3] || s[3] == s[4])
    {
        y++;
        s = to_string(y);
    }

    cout << y << ln;

    return 0;
}