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
    cin >> n;

    v64 p(n + 1), ans(n + 1);

    forn(i, 1, n + 1)
    {
        cin >> p[i];
        ans[p[i]] = i;
    }

    forn(i, 1, n + 1)
    {
        cout << ans[i] << " ";
    }
    cout << ln;

    return 0;
}