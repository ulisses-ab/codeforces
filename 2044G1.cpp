#include <bits/stdc++.h>
 
#define WHITE 0
#define GREY 1
#define BLACK 2
#define RED 3
 
using namespace std;
using ll = long long;
 
int n, m, q;
int nextN[200010], parent[200010], color[200010], distt[200010];
 
int dfs2(int current) {
    if(distt[current] != -1) return distt[current];
 
    if(color[current] == RED) {
        return distt[current] = 0;
    }
 
    return distt[current] = dfs2(nextN[current]) + 1;
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
 
    for(int i = 1; i <= n; i++) cin >> nextN[i];
    for(int i = 1; i <= n; i++) color[i] = WHITE;
    for(int i = 1; i <= n; i++) dfs(i);
    for(int i = 1; i <= n; i++) distt[i] = -1;
 
    int maxD = 0;
    for(int i = 1; i <= n; i++) {
        maxD = max(maxD, dfs2(i));
    }
 
    cout << maxD + 2 << endl;
 
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}