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

    vector<ll> animal_strengths(n);
    forn(i, 0, n)
    {
        cin >> animal_strengths[i];
    }
    sort(animal_strengths.begin(), animal_strengths.end());

    vector<ll> prefix_sum(n + 1, 0);
    // prefix_sum[0] = animal_strengths[0]; 
    for (ll i = n - 1; i >= 0; i--)
    {
        prefix_sum[i] = prefix_sum[i + 1] + animal_strengths[i];
    }

    ll first_survivor_index = n - 1;
    long long survivor_sum = animal_strengths[n - 1];

    for (ll i = n - 2; i >= 0; i--)
    {
        ll sum_total = prefix_sum[i];
        if (2* survivor_sum <= sum_total)
        {
            first_survivor_index = i;
            survivor_sum = sum_total;
        }
    }

    cout << (n - first_survivor_index) << "\n";

    return 0;
}