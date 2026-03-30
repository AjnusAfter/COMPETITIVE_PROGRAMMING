#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

// #define LLONG_MAX 10 ^ 9 + 1

ll busca_binaria(const vector<ll> &k, ll t, ll esq, ll dir)
{
    while (esq < dir) // not <=
    {
        ll meio = esq + (dir - esq) / 2;

        ll products = 0;
        // Testa se mid é suficiente
        for (ll machine : k)
        {
            products += meio / machine;
            if (products >= t)
                break;
        }

        if (products >= t)
        {
            dir = meio;
        }
        else
        {
            esq = meio + 1;
        }
    }

    return esq; // "the minimum time needed"
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, t;
    cin >> n >> t;

    vector<ll> k(n);
    // ll mn = LLONG_MAX;
    forn(i, 0, n)
    {
        cin >> k[i];
        // mn = min(mn, k[i]);                        // O(n)
    }

    // sort(k.begin(), k.end());                      // O(n log n)

    ll mn = *min_element(k.begin(), k.end()); // O(n)

    /*
    cout << "n: " << n << "\n";
    cout << "t: " << t << "\n";
    forn(i, 0, k.size())
    {
        cout << "k" << i + 1 << ": " << k[i] << "\n";
    }

    ll tempo = 0;
    forn(i, 0, k.size())
    {
        tempo += t / k[i];
        cout << "tempo " << i << ": " << tempo << "\n";
    }

    cout << tempo << "\n";
    */

    ll menor_t_possivel = 0;
    ll maior_t_possivel = mn * t;

    cout << busca_binaria(k, t, menor_t_possivel, maior_t_possivel) << "\n";

    return 0;
}
