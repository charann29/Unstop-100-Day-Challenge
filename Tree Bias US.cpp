#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &adj, int depth, int node, int par, int target)
{
    if (node == target)
        return depth;
    int ans = 0;
    for (auto it : adj[node])
    {
        if (it != par)
            ans += dfs(adj, depth + 1, it,
                       node, target);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int val = dfs(adj, 0, 1, -1, i)
            ans += val;
    }
}

// ------------------------------------------------------------------------------------------------------------------------------------------------
// Optimized Solution : Without the recursion calls!

#include <bits/stdc++.h>
using namespace std;

int ans = 0; // ans for storing sum of all depth

void dfs(vector<vector<int>> &adj, int depth, int node, int par)
{
    ans += depth;
    for (auto it : adj[node])
    {
        if (it != par)
            dfs(adj, depth + 1, it, node);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); // building the adjacency list
        adj[b].push_back(a);
    }
    dfs(adj, 0, 1, -1);
    cout << ans << endl;
    return 0;
}