#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    _;

    ll n, x;
    cin >> n >> x;

    v64 array(n);

    forn(i, 0, n)
    {
        cin >> array[i];
    }

    ll left_pointer = 0;
    ll current_sum = 0;
    ll subarrays_count = 0;

    forn(right_pointer, 0, n)
    {
        current_sum += array[right_pointer];

        while (current_sum > x)
        {
            {
                current_sum -= array[left_pointer];
                left_pointer++;
            }
        }

        if (current_sum == x)
        {
            subarrays_count++;
        }
    }

    cout << subarrays_count << "\n";

    return 0;
}