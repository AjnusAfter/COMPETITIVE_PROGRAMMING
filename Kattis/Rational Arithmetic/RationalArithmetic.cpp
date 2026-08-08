#include <bits/stdc++.h>
#include <numeric>
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

    ll t;
    cin >> t;

    while (t--)
    {
        ll x1, y1, x2, y2, num, dem, div;
        char op;

        cin >> x1 >> y1 >> op >> x2 >> y2;

        switch (op)
        {
        case '+':
            num = x1 * y2 + x2 * y1;
            dem = y1 * y2;
            break;
        case '-':
            num = x1 * y2 - x2 * y1;
            dem = y1 * y2;
            break;
        case '*':
            num = x1 * x2;
            dem = y1 * y2;
            break;
        case '/':
            num = x1 * y2;
            dem = y1 * x2;
            break;
        }

        div = gcd(num, dem);
        if (div > 1)
        {
            num /= div;
            dem /= div;
        }

        if (dem < 0)
        {
            num = -num;
            dem = -dem;
        }

        cout << num << " / " << dem << ln;
    }

    return 0;
}