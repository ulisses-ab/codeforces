#include <bits/stdc++.h>
 
using namespace std;
using lli = unsigned long long int;
 
int n, m;
bool searched[110];
vector<vector<int>> graph;
vector<vector<pair<int, int>>> filmGraph;
vector<set<int>> filmSet;
vector<int> ans;
 
bool dfs(int c, set<int> d) {
    if(searched[c]) return false;
    searched[c] = true;
 
    if(d.count(c) != 0) return true;
 
    for(auto connection : filmGraph[c]) {
        if(dfs(connection.first, d)) {
            ans.push_back(connection.first);
            ans.push_back(connection.second);
            return true;
        }
    }
 
    return false;
}
 
void query(int xi, int yi) {
    ans.clear();
 
    set<int> d;
    for(auto x : graph[yi + n]) {
        d.insert(x);
    }
 
    for(auto f : graph[xi + n]) {
        for(int i = 0; i < n; i++) searched[i] = false;
        if(dfs(f, d)) {
            cout << 2 + ans.size() / 2 << endl;
            cout << xi + 1 << " " << f + 1 << " ";
            for(int i = ans.size() - 1; i >= 0; i--) {
                if(ans[i] >= n) ans[i] -= n;
                cout << ans[i] + 1 << " ";
            }
            cout << yi + 1 << endl;
 
            return;
        }
    }
 
    cout << -1 << endl;
}
 
int main() {
    cin >> n >> m;
 
    graph.resize(n + m);
 
    for(int i = 0; i < n; i++) {
        int ni;
        cin >> ni;
        for(int j = 0; j < ni; j++) {
            int mj;
            cin >> mj;
            mj--;
 
            graph[i].push_back(n + mj);
            graph[n + mj].push_back(i);
        }
    }
 
    filmGraph.resize(n);
    filmSet.resize(n);
 
    for(int i = n; i < graph.size(); i++) {
        for(int j = 1; j < graph[i].size(); j++) {
            if(filmSet[graph[i][j]].count(graph[i][j - 1]) == 0) {
                filmGraph[graph[i][j]].push_back(make_pair(graph[i][j - 1], i));
                filmGraph[graph[i][j - 1]].push_back(make_pair(graph[i][j], i));
                filmSet[graph[i][j]].insert(graph[i][j - 1]);
                filmSet[graph[i][j - 1]].insert(graph[i][j]);
            }
        }
    }
 
    int q;
    cin >> q;
 
    while(q--) {
        int xi, yi;
        cin >> xi >> yi;
        xi--; yi--;
 
        query(xi, yi);
    }
    return 0;
}