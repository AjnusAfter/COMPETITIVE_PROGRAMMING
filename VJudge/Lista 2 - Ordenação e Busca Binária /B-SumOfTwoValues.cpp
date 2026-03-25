#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

int busca_binaria(vector<pair<ll, ll>> &vec, ll target, ll esq, ll dir)
{
    while (esq <= dir)
    {
        ll meio = esq + (dir - esq) / 2;

        if (vec[meio].first == target)
        {
            return meio;
        }
        else if (vec[meio].first < target)
        {
            esq = meio + 1;
        }
        else
        {
            dir = meio - 1;
        }
    }

    return -1;
}

int main()
{
    ll n, x;
    cin >> n >> x;

    vector<pair<ll, ll>> A(n);

    forn(i, 0, n)
    {
        cin >> A[i].first;
        A[i].second = i + 1;
    }

    sort(A.begin(), A.end());

    forn(i, 0, n)
    {
        ll par_1 = A[i].first;
        ll par_2 = x - par_1;

        ll idx = busca_binaria(A, par_2, i + 1, n - 1);

        if (idx != -1)
        {
            ll j = idx;

            if (A[i].second < A[idx].second)
            {
                cout << A[i].second << " " << A[idx].second << "\n";
            }
            else
            {
                cout << A[idx].second << " " << A[i].second << "\n";
            }

            return 0;
        }
    }

    cout << "IMPOSSIBLE";

    /* sem busca binária: (O(n))
    ll l = 0;
    ll r = n - 1;

    while (l < r)
    {
        ll soma = A[l].first + A[r].first;

        if (soma == x)
        {
            cout << A[l].second << " " << A[r].second << "\n";
            return 0;
        }
        else if (soma < x)
            l++;
        else
            r--;
    }

    cout << "IMPOSSIBLE\n";*/

    return 0;
}
