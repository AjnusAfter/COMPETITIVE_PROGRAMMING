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

    ll n, m;
    cin >> n >> m;

    vector<v64> adj(n + 1);
    forn(i, 0, n - 1)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll LOG = 0;
    while ((1LL << LOG) <= n)
        LOG++;

    vector<v64> up(n + 1, v64(LOG, 0));
    v64 depth(n + 1, 0), parent(n + 1, 0), order;

    order.reserve(n);
    stack<ll> st;
    st.push(1);
    parent[1] = 0;

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
            depth[v] = depth[u] + 1;
            up[v][0] = u;
            forn(j, 1, LOG)
            {
                up[v][j] = up[up[v][j - 1]][j - 1];
            }
            st.push(v);
        }
    }

    auto lca = [&](ll a, ll b)
    {
        if (depth[a] < depth[b])
            swap(a, b);

        ll diff = depth[a] - depth[b];
        forn(j, 0, LOG)
        {
            if (diff & (1LL << j))
                a = up[a][j];
        }

        if (a == b)
            return a;

        for (ll j = LOG - 1; j >= 0; j--)
        {
            if (up[a][j] != up[b][j])
            {
                a = up[a][j];
                b = up[b][j];
            }
        }

        return up[a][0];
    };

    v64 cnt(n + 1, 0);

    while (m--)
    {
        ll a, b;
        cin >> a >> b;

        ll c = lca(a, b);
        cnt[a]++;
        cnt[b]++;
        cnt[c]--;
        if (parent[c] != 0)
            cnt[parent[c]]--;
    }

    for (ll i = n - 1; i >= 0; i--)
    {
        ll u = order[i];
        if (parent[u] != 0)
            cnt[parent[u]] += cnt[u];
    }

    forn(i, 1, n + 1) cout << cnt[i] << " ";
    cout << ln;

    return 0;
}