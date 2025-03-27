
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int n, q;
int odd[2010], even[2010], parent[2010];
 
void find(bool isOdd, int current, priority_queue<int>& pq) {
    if(current == 0) return;
 
    if(!isOdd) {
        find(true, parent[current], pq);
        return;
    }
 
    pq.push(odd[current] - (1 + even[parent[current]]));
    find(false, parent[current], pq);
}
 
void dfs(int current, int p, vector<vector<int>>& graph) {
    parent[current] = p;
 
    even[current] = odd[p] + 1;
    odd[current] = even[p] + (2 * graph[current].size()) - 1;
 
    for(auto next : graph[current]) {
        if(next == p) continue;
 
        dfs(next, current, graph);
    }
}
 
void testcase() {
    cin >> n >> q;
    
    vector<vector<int>> graph(n, vector<int>());
 
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
 
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    odd[0] = 0;
    even[0] = 0;
    for(auto next : graph[0]) {
        dfs(next, 0, graph);
    }
 
 
    for(int i = 0; i < q; i++) {
        int vi, pi;
        cin >> vi >> pi;
        vi--;
 
        priority_queue<int> pq;
 
        find(false, vi, pq);
 
        int ans = even[vi];
 
        while(pi-- && !pq.empty()) {
            ans -= pq.top();
            pq.pop();
        }
 
        cout << ans << endl;
    }
}
 
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}