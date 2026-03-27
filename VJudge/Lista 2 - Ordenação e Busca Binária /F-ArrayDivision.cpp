#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

ll busca_binaria(const vector<ll> &a, ll n, ll k, ll esq, ll dir)
{
    ll resposta = dir;

    while (esq <= dir)
    {
        ll mid = (esq + dir) / 2;

        ll current_sum = 0;
        ll parts = 1;

        forn(i, 0, n)
        {
            if (current_sum + a[i] > mid)
            {
                parts++;
                current_sum = a[i];
            }
            else
            {
                current_sum += a[i];
            }
        }

        if (parts <= k)
        {
            resposta = mid;
            dir = mid - 1;
        }
        else
        {
            esq = mid + 1;
        }
    }

    return resposta;
}

int main()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> array(n);

    forn(i, 0, n)
    {
        cin >> array[i];
    }

    ll total_sum = 0;
    ll max_elem = 0;

    forn(i, 0, n)
    {
        total_sum += array[i];
        max_elem = max(max_elem, array[i]);
    }

    ll low = max_elem;
    ll high = total_sum;

    cout << busca_binaria(array, n, k, low, high) << "\n";

    return 0;
}