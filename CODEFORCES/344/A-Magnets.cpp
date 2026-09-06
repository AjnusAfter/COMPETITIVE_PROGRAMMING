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

    string prev, cur;
    cin >> prev;

    ll groups = 1;
    forn(i, 1, n)
    {
        cin >> cur;

        if (cur != prev)
        {
            groups++;
        }

        prev = cur;
    }

    cout << groups << ln;

    return 0;
}