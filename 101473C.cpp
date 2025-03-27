#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int n, m, q;
int age[510], dict[510];
vector<int> graph[510];
bool visited[510];
 
int dfs(int current) {
    int minAge = 1000000;
 
    for(int next : graph[current]) {
        if(visited[next]) continue;
 
        minAge = min(minAge, age[next]);
        visited[next] = true;
 
        minAge = min(minAge, dfs(next));
    }
 
    return minAge;
}
 
int main() {
    cin >> n >> m >> q;
 
    for(int i = 1; i <= n; i++) cin >> age[i];
    for(int i = 1; i <= n; i++) dict[i] = i;
 
    for(int i = 1; i <= m; i++) {
        int manager, managed;
        cin >> manager >> managed;
        graph[managed].push_back(manager);
    }
 
    for(int i = 1; i <= q; i++) {
        char queryType;
        cin >> queryType;
 
        if(queryType == 'T') {
            int a, b;
            cin >> a >> b;
            swap(age[dict[a]], age[dict[b]]);
            swap(dict[a], dict[b]);
        }
        else { 
            int x;
            cin >> x;
 
            for(int i = 1; i <= n; i++) visited[i] = false;
            int r = dfs(dict[x]);
 
            if(r == 1000000) cout << "*" << endl;
            else cout << r << endl;
        }
    }
}