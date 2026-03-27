#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

int main()
{
    ll n, x;
    cin >> n >> x;

    multiset<ll> children;
    forn(i, 0, n)
    {
        ll p;
        cin >> p;
        children.insert(p);
    }

    ll gondolas_ocupadas = 0;
    while (!children.empty())
    {
        auto it_heaviest = prev(children.end());
        ll heaviest = *it_heaviest;
        children.erase(it_heaviest);

        ll peso_restante = x - heaviest;

        // busca mais pesado coleguinha <= peso_restante
        auto it_coleguinha = children.upper_bound(peso_restante);

        if (it_coleguinha != children.begin())
        {
            --it_coleguinha; // coleguinha válido
            children.erase(it_coleguinha);
        }

        gondolas_ocupadas++;
    }

    cout << gondolas_ocupadas << "\n";

    return 0;
}
