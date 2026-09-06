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

ll BFS(const unordered_map<string, vector<string>> &adj, const string &start)
{
    queue<pair<string, ll>> q;
    unordered_set<string> vis;

    for (const string &nxt : adj.at(start))
    {
        q.push({nxt, 1});
        vis.insert(nxt);
    }

    while (!q.empty())
    {
        auto [cur, dist] = q.front();
        q.pop();

        if (cur == start)
            return dist;

        if (!adj.count(cur))
            continue;

        for (const string &nxt : adj.at(cur))
        {
            if (!vis.count(nxt))
            {
                vis.insert(nxt);
                q.push({nxt, dist + 1});
            }
        }
    }

    return -1;
}

int main()
{
    _;

    ll n;
    cin >> n;

    string start;
    cin >> start;

    unordered_map<string, vector<string>> adj;

    forn(i, 0, n)
    {
        string u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    if (!adj.count(start))
    {
        cout << "NO BLACK HOLE" << ln;
        return 0;
    }

    ll ans = BFS(adj, start);

    if (ans == -1)
    {
        cout << "NO BLACK HOLE" << ln;
    }

    else
    {
        cout << ans << ln;
    }

    return 0;
}