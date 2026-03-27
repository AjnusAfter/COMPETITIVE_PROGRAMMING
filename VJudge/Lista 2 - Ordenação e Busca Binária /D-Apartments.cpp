#include <bits/stdc++.h>
#include <set>
using namespace std;

typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> applicants(n);
    forn(i, 0, n)
    {
        cin >> applicants[i];
    }

    multiset<ll> apartments;
    forn(i, 0, m)
    {
        ll x;
        cin >> x;
        apartments.insert(x);
    }

    sort(applicants.begin(), applicants.end());

    ll converted_applicants = 0;
    forn(i, 0, n)
    {
        ll min_size_aceito = applicants[i] - k;
        ll max_size_aceito = applicants[i] + k;

        // menor apartamento >= min_size_aceito
        auto it = apartments.lower_bound(min_size_aceito);

        if (it != apartments.end() && *it <= max_size_aceito)
        {
            converted_applicants++;
            apartments.erase(it); // remove ap alocado
        }
    }

    cout << converted_applicants << "\n";

    return 0;
}