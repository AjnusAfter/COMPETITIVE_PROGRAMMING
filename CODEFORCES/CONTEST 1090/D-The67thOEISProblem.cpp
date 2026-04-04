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

bool isPrime(ll x, const v64 &primes)
{
    for (ll p : primes)
    {
        if (p * p > x)
        {
            break;
        }

        if (x % p == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    _;

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        v64 primes;
        primes.reserve((size_t)n + 1);
        primes.push_back(2);

        for (ll x = 3; (ll)primes.size() < n + 1; x += 2)
        {
            if (isPrime(x, primes))
            {
                primes.push_back(x);
            }
        }

        forn(i, 0, n)
        {
            ll a = primes[i] * primes[i + 1];
            cout << a << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}