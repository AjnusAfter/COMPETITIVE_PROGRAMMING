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

    ll N;
    cin >> N;

    ll dpA = 0, dpB = 0, dpC = 0;

    forn(i, 0, N)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        ll newA = a + max(dpB, dpC);
        ll newB = b + max(dpA, dpC);
        ll newC = c + max(dpA, dpB);

        dpA = newA;
        dpB = newB;
        dpC = newC;
    }

    cout << max({dpA, dpB, dpC}) << ln;

    return 0;
}