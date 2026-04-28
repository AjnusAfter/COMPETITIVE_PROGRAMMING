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

    ll n;
    cin >> n;

    ll a_count = 0, d_count = 0;
    string ans;

    forn(i, 0, n)
    {
        char c;
        cin >> c;

        if (c == 'A')
        {
            a_count++;
        }
        else
        {
            d_count++;
        }
    }

    if (a_count > d_count)
    {
        ans = "Anton";
    }
    else if (d_count > a_count)
    {
        ans = "Danik";
    }
    else
    {
        ans = "Friendship";
    }

    cout << ans << ln;

    return 0;
}