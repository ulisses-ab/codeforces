#include <bits/stdc++.h>
 
#define WHITE 0
#define GREY 1
#define BLACK 2
#define RED 3
 
using namespace std;
using ll = long long;
 
int n, m, q;
int nextN[200010], color[200010];
vector<int> parents[200010];
 
int dfs2(int current) {
    int ans = 1;
 
    for(auto parent : parents[current]) {
        ans += dfs2(parent);
    }
 
    return ans;
}
 
int dfs(int current) {
    if(color[current] == RED) {
        return -1;
    }
 
    if(color[current] == BLACK) {
        return -1;
    }
 
 
    color[current] = GREY;
 
    if(color[nextN[current]] == GREY) {
        color[current] = RED;
        return nextN[current];
    }
 
    if(color[nextN[current]] == BLACK || color[nextN[current]] == RED) {
        color[current] = BLACK;
        return -1;
    }
 
    int b = dfs(nextN[current]);                                               
    if(b != -1) {
        color[current] = RED;
        if(b == current) {
            return -1;
        }
    }
    else {
        color[current] = BLACK;
    }
 
    return b;
}
 
void testcase() {
    int n;
    cin >> n;
 
    for(int i = 1; i <= n; i++) parents[i].clear();
    for(int i = 1; i <= n; i++) {
        cin >> nextN[i];
        parents[nextN[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) color[i] = WHITE;
    for(int i = 1; i <= n; i++) dfs(i);
 
    vector<int> roots;
 
 
    for(int i = 1; i <= n; i++) {
        if(color[i] == RED) {
            for(auto parent : parents[i]) {
                if(color[parent] == RED) continue;
                roots.push_back(parent);
            }
        }
    }
 
 
    int maxD = 0;
    for(auto root : roots) {
        maxD = max(maxD, dfs2(root));
    }
 
    cout << maxD + 2 << endl;
 
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}