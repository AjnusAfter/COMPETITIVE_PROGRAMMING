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

    ll count = 0;
    forn(i, 0, s.size())
    {
        if (s[i] == s[i + 1])
        {
            count++;
        }
    }

    cout << count << ln;

    return 0;
}