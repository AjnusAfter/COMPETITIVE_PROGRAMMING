#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef pair<ll, ll> p64;

#define _                    \
    ios::sync_with_stdio(0); \
    cin.tie(0)
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"

int main()
{
    _;

    ll n;
    cin >> n;

    vector<v64> adj(n + 1);
    forn(i, 0, n - 1)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    v64 parent(n + 1, 0), order;
    order.reserve(n);

    stack<ll> st;
    st.push(1);
    parent[1] = -1;

    while (!st.empty())
    {
        ll u = st.top();
        st.pop();
        order.push_back(u);

        for (ll v : adj[u])
        {
            if (v == parent[u])
                continue;
            parent[v] = u;
            st.push(v);
        }
    }

    vector<array<ll, 2>> dp(n + 1, {0, 0});

    for (ll i = n - 1; i >= 0; i--)
    {
        ll u = order[i];

        ll sum = 0;
        for (ll v : adj[u])
        {
            if (v == parent[u])
                continue;
            sum += max(dp[v][0], dp[v][1]);
        }

        dp[u][0] = sum;
        dp[u][1] = 0;

        for (ll v : adj[u])
        {
            if (v == parent[u])
                continue;
            dp[u][1] = max(dp[u][1], sum - max(dp[v][0], dp[v][1]) + dp[v][0] + 1);
        }
    }

    cout << max(dp[1][0], dp[1][1]) << ln;

    return 0;
}