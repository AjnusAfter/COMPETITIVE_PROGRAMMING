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

    ll x = 0;

    string op_var;

    forn(i, 0, n)
    {
        cin >> op_var;

        if (op_var[1] == '+')
        {
            x++;
        }
        else
        {
            x--;
        }
    }

    cout << x << ln;

    return 0;
}