#include <bits/stdc++.h>
 
using namespace std;
 
pair<pair<int, int>, bool> dfs(vector<vector<int>>& graph, int current, int parent)  {
    //first: max if the path enters here
    //second: max of a path inside here
 
    int children = graph[current].size();
    if(parent != -1) children--;
    int maxPath = 0;
    int maxPath2 = 0;
    int maxPathInside = 0;
    bool maxPathInsideTouchesCurrent = true;
    for(auto next : graph[current]) {
        if(next == parent) continue;
 
        pair<pair<int, int>, bool> p = dfs(graph, next, current);
 
        if(p.first.first > maxPath) {
            maxPath2 = maxPath;
            maxPath = p.first.first;
        }
        else if(p.first.first > maxPath2) {
            maxPath2 = p.first.first;
        }
 
        if(p.second) {
            maxPathInside = max(maxPathInside, p.first.second + 1);
        }
        else {
            maxPathInside = max(maxPathInside, p.first.second);
        }
    }
 
 
 
    int maxPathInside2 = max(maxPath2 + maxPath + children - 2, max(maxPath + children - 1, children));
    //cout << maxPath2 + maxPath << " " << maxPath + children - 1 << " " << children << maxPathInside;
    if(maxPathInside > maxPathInside2) {
        maxPathInsideTouchesCurrent = false;
        maxPathInside2 = maxPathInside;
    }
 
    maxPath = maxPath + children - 1;
    maxPath = max(maxPath, children);
 
 
    //cout << current << ": " << maxPath << " " << maxPathInside2 << " " << maxPathInsideTouchesCurrent << endl;
    return make_pair(make_pair(maxPath, maxPathInside2), maxPathInsideTouchesCurrent);
}
 
void testcase() {
    int n;
    cin >> n;
 
    vector<vector<int>> graph(n, vector<int>(0));
 
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
 
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
 
 
    cout << dfs(graph, 0, -1).first.second << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
 
    return 0;
}