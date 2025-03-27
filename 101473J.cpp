#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int n, m, s;
 
vector<vector<int>> graph[200010];
vector<vector<int>> tree[200010];
pair<int, int> ancestor[200010][20];
int lvl[200010];
 
void prim() {
    priority_queue<vector<int>> pq;
    set<int> visited;
 
    visited.insert(1);
    for(auto edge : graph[1]) pq.push(edge);
 
    while(!pq.empty()) {
        vector<int> edge = pq.top();
        pq.pop();
 
        if(visited.count(edge[2]) != 0) continue;
 
        visited.insert(edge[2]);
 
        tree[edge[1]].push_back({edge[0], edge[1], edge[2]});
        tree[edge[2]].push_back({edge[0], edge[2], edge[1]});
 
 
        for(auto nextEdge : graph[edge[2]]) {
            pq.push(nextEdge);
        }
    }
}
 
void dfs(int current, int parent, int level) {
    lvl[current] = level;
 
    for(auto edge : tree[current]) {
        int child = edge[2];
 
        if(child == parent) {
            ancestor[current][0] = {parent, edge[0]};
            continue;
        };
 
        dfs(child, current, level + 1);
    }
}
 
pair<int, int> solveAncestor(int node, int rank) {
    if(ancestor[node][rank].first != -1) return ancestor[node][rank];
 
    pair<int, int> a = solveAncestor(node, rank - 1);
    pair<int, int> b = solveAncestor(a.first, rank - 1);
 
    return ancestor[node][rank] = {b.first, min(a.second, b.second)};
}
 
pair<int, int> getAncestor(int node, int rank) {
    if(rank == 0) return {node, 1000000000};
 
    for(int i = 19; i >= 0; i--) {
        if(rank >= 1 << i) {
            pair<int, int> a = ancestor[node][i];
            pair<int, int> b = getAncestor(a.first, rank - (1 << i));
 
            return {b.first, min(a.second, b.second)};
        }
    }
 
    return {0, 0};
}
 
pair<int, int> lca(int node1, int node2) {
    if(node1 == node2) return {node1, 1000000000};
 
    if(lvl[node1] > lvl[node2]) {
        pair<int, int> a = getAncestor(node1, lvl[node1] - lvl[node2]);
        pair<int, int> b = lca(node2, a.first);
        return {b.first, min(a.second, b.second)};
    }
 
    if(lvl[node2] > lvl[node1]) {
        pair<int, int> a = getAncestor(node2, lvl[node2] - lvl[node1]);
        pair<int, int> b = lca(node1, a.first);
        return {b.first, min(a.second, b.second)};
    }
 
    for(int i = 19; i >= 0; i--) {
        if(ancestor[node1][i].first != ancestor[node2][i].first) {
            pair<int, int> a = ancestor[node1][i];
            pair<int, int> b = ancestor[node2][i];
            pair<int, int> c = lca(a.first, b.first);
            return {c.first, min(min(a.second, b.second), c.second)};
        }
    }
 
    return {ancestor[node1][0].first, min(ancestor[node2][0].second, ancestor[node1][0].second)};
}
 
void testcase() {
    cin >> n >> m >> s;
 
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 20; j++) {
            ancestor[i][j] = {-1, -1};
        }
    }
    ancestor[1][0] = {0, 0};
 
    for(int i = 1; i <= n; i++) graph[i].clear();
 
    for(int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
 
        graph[a].push_back({w, a, b});
        graph[b].push_back({w, b, a});
    }
 
    prim();
    dfs(1, 0, 0);
 
    for(int i = 1; i <= n; i++) solveAncestor(i, 19);
 
    /*for(int i = 1; i <= n; i++) {
        cout << i << ": ";
        for(int j = 0; j < 20; j++) {
            cout << ancestor[i][j] << " ";
        }
        cout << endl;
    }
 
    for(int i = 1; i <= n; i++) {
        for(auto edge : tree[i]) {
            cout << edge[1] << " " << edge[2] << "/" << edge[0] << endl;
        }
        cout << endl;
    }*/
 
    for(int i = 1; i <= s; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b).second << endl;
    }
}
 
int main() {
    int t;
    t = 1;
    
    while(t--) testcase();
    return 0;
}