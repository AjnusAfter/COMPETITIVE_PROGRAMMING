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

    vector<ll> vec(n);

    forn(i, 0, n)
    {
        cin >> vec[i];
    }

    stack<pair<ll, ll>> st;

    forn(i, 0, n)
    {
        while (!st.empty() && st.top().first >= vec[i])
            st.pop();

        if (st.empty())
            cout << 0 << " ";
        else
            cout << st.top().second << " ";

        st.push({vec[i], i + 1});
    }

    return 0;
}