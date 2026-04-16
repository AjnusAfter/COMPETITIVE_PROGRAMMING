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

ll sum_xor(ll n)
{
    if (n == 0)
    {
        return 1;
    }

    ll zero_bits = 0;

    while (n > 0)
    {
        if ((n & 1) == 0)
        {
            zero_bits++;
        }

        n = n >> 1;
    }

    return 1L << zero_bits;

    /*
    // cout << "entrou n: " << n << ln << ln;
    ll x = 0;

    ll i = 0;
    do
    {
        // cout << "n: " << n << "; " << "x: " << x << ln;

        // cout << "comparando " << n << " + " << i << " == " << n << " ^ " << i << ln;
        // cout << n + i << " | " << (n ^ i) << ln;
        if (n + i == (n ^ i))
        {
            x++;
        }

        i++;
    } while (i < n);


    return x;
    */
}

int main()
{
    _;

    ll n;
    cin >> n;

    cout << sum_xor(n) << ln;

    return 0;
}