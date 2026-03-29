#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

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

    // ✅ Compressão usando map
    map<ll, ll> compress;
    forn(i, 0, n)
    {
        compress[array[i]] = 0; // só cria as chaves
    }

    ll idx = 0;
    for (auto &p : compress)
        p.second = idx++; // atribui índice crescente

    // substitui valores no array
    forn(i, 0, n)
    {
        array[i] = compress[array[i]];
    }

    // ✅ Sliding Window
    vector<ll> freq(idx, 0);
    ll left_pointer = 0;
    ll distinct = 0;
    ll subarrays_required = 0;

    forn(right_pointer, 0, n)
    {
        if (freq[array[right_pointer]] == 0)
            distinct++;

        freq[array[right_pointer]]++;

        while (distinct > x)
        {
            freq[array[left_pointer]]--;
            if (freq[array[left_pointer]] == 0)
                distinct--;
            left_pointer++;
        }

        subarrays_required += (right_pointer - left_pointer + 1);
    }

    cout << subarrays_required << "\n";

    return 0;
}