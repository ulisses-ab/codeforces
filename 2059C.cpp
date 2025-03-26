#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int grid[310][310];
 
int v[310];
 
void testcase() {
    int n; 
    cin >> n;
 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
        grid[i][n + 1] = 0;
    }
 
    for(int i = 1; i <= n; i++) {
        for(int j = n; j >= 1; j--) {
            grid[i][j] += grid[i][j + 1];
        }
    }
 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            grid[i][j] = grid[i][j + 1];
        }
    }
 
 
    vector<int> vv;
 
    for(int i = 1; i <= n; i++) {
        int c = 0;
        for(int j = n; j >= 1; j--) {
            if(grid[i][j] == c) c++;
            else break;
        }
       vv.push_back(c-1);
    }
 
    sort(vv.begin(), vv.end());
 
    int c = 0;
    for(int i = 0; i < n; i++) {
        if(vv[i] >= c) c++;
    }
 
    cout << c << endl;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) testcase();
    return 0;
}