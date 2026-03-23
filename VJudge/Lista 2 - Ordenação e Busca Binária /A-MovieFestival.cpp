#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<pair<ll, ll>> filmes(n);

    forn(i, 0, n)
    {
        cin >> filmes[i].first >> filmes[i].second;
    }
    sort(filmes.begin(), filmes.end(),
         [](auto &filme_a, auto &filme_b)
         {
             return filme_a.second < filme_b.second;
         });

    /*
    int i = 0;
    for (auto &[start, end] : filmes)
    {
        cout << "[" << i << "]" << " -> "
             << start << " "
             << end << "\n";
        i++;
    }
        */

    /*for (auto &[chave, par] : filmes)
    {
        if ()
    }*/

    ll fim_atual = 0;
    ll will_watch = 0;

    for (auto &f : filmes)
    {
        if (f.first >= fim_atual)
        {
            will_watch++;
            fim_atual = f.second;
        }
    }

    cout << will_watch << "\n";

    return 0;
}
