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

    ll N;
    cin >> N;

    ll count = 0;
    for (ll num = 11; num <= N; num += 2)
    {
        ll divisors = 0;
        for (ll d = 1; d * d <= num; d++)
        {
            if (num % d == 0)
            {
                divisors++;

                if (d != num / d)
                {
                    divisors++;
                }
            }
        }

        if (divisors == 8)
        {
            count++;
        }
    }

    cout << count << ln;

    return 0;
}