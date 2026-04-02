#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define lnm "\n"

int main()
{
    _;
    ll n, m;
    /*
    cin >> n >> m;

    // "The last case will be followed by a case where n = m = 0, which should not be processed."
    if (n == m == 0)
    {
        return 0;
    }
    */

    // "Input consists of a series of test cases (at most 20)"
    // "The last case will be followed by a case where n = m = 0, which should not be processed."
    ll tc = 0;
    while (cin >> n >> m && !(n == 0 && m == 0) && tc < 20)
    {
        tc++;
        // g[u] = lista de pares (vizinho, fator)
        vector<vector<pair<ll, double>>> g(n);

        forn(i, 0, m)
        {
            ll u, v;
            double f;
            cin >> u >> v >> f;

            // aresta u -> v com fator f
            g[u].push_back({v, f});
            // aresta v -> u com fator f (grafo não direcionado)
            g[v].push_back({u, f});
        }

        // best[v] = melhor produto encontrado até v
        vector<double> best(n, 0.0);
        best[0] = 1.0;

        // max-heap: maior produto sai primeiro
        priority_queue<pair<double, ll>> pq;
        pq.push({1.0, 0});

        while (!pq.empty())
        {
            auto [prod, u] = pq.top();
            pq.pop();

            // se este estado está desatualizado, ignora
            if (prod < best[u])
                continue;

            // se chegou no destino, já pode parar
            if (u == n - 1)
                break;

            // tenta melhorar todos os vizinhos
            for (auto [v, f] : g[u])
            {
                double novo = prod * f;

                if (novo > best[v])
                {
                    best[v] = novo;
                    pq.push({novo, v});
                }
            }
        }

        cout << fixed << setprecision(4) << best[n - 1] << '\n';
    }

    return 0;
}