#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
ll v[200010];
ll r[200010];
ll l[200010];
 
vector<vector<ll>> graph;
vector<vector<ll>> vl;
ll ans[200010];
ll p[200010];
 
ll dfs2(ll current, ll parent) {
    ll val = 0;
    for(auto next : graph[current]) {
        if(next == parent) continue;
 
        val = max(val, dfs2(next, current));
    }
 
    return v[current] = max(l[current], min(r[current], val));
}
 
void dfs(ll current, ll parent, ll level) {
    p[current] = parent;
    vl[level].push_back(current);
 
    for(auto next : graph[current]) {
        if(next == parent) continue;
 
        dfs(next, current, level + 1);
    }
}
 
void testcase() {
    graph.clear();
    vl.clear();
 
    ll n;
    cin >> n;
 
    ll dump;
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
 
    graph.resize(n);
    for(int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
 
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    vl.resize(n);
    dfs2(0, -1);
    dfs(0, -1, 0);
 
    ans[0] = v[vl[0][0]];
 
    for(int i = 1; i < n; i++) {
        ans[i] = ans[i - 1];
 
        for(auto x : vl[i]) {
            if(v[x] - v[p[x]] <= 0) continue;
 
            ans[i] += v[x] - v[p[x]];
        }
    }
 
    cout << ans[n - 1] << endl;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) testcase();
    return 0;
}