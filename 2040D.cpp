#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int n;
vector<vector<int>> graph;
int toAdd[200010];
int a[200010];
 
void dfs2(int current, int parent, int add) {
    add += toAdd[current];
 
    a[current] = 1 + add;
 
    for(auto next : graph[current]) {
        if(next == parent) continue;
 
        dfs2(next, current, add);
    }
}
 
int dfs(int current, int parent) {
    int size = 0;
 
    int add = 1;
    for(auto next : graph[current]) {
        if(next == parent) continue;
 
        toAdd[next] = add;
        int subtreeSize = dfs(next, current);
        size += subtreeSize;
        add += 2 * subtreeSize;
        if(add % 2 != 0) add++;
    } 
 
    return size + 1;
}