#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
ll grid[210][210];
ll dp[210][210][210];
ll minimal[210][210];
 
ll n, m, k;
 
void testcase() {
    cin >> n >> m >> k;
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            minimal[i][j] = 1e17;
        }
    }
 
    for(int s = 0; s < m; s++) {
        dp[0][0][s] = grid[0][s] + k * s;
        minimal[0][0] = min(minimal[0][0], dp[0][0][s]); 
    }
 
    for(int i = 1; i < n; i++) {
        for(int s = 0; s < m; s++) {
            dp[i][0][s] = minimal[i-1][0] + grid[i][s] + k * s;
            minimal[i][0] = min(minimal[i][0], dp[i][0][s]); 
        }
    }
 
    for(int j = 1; j < m; j++) {
        for(int s = 0; s < m; s++) {
            dp[0][j][s] = dp[0][j-1][s] + grid[0][(j+s)%m];
            minimal[0][j] = min(minimal[0][j], dp[0][j][s]); 
        }
    }
 
    for(int j = 1; j < m; j++) {
        for(int i = 1; i < n; i++) {
            for(int s = 0; s < m; s++) {
                dp[i][j][s] = min(dp[i][j-1][s], minimal[i-1][j] + k * s) + grid[i][(j+s)%m];
                minimal[i][j] = min(minimal[i][j], dp[i][j][s]);
            }
        }
    }
 
    cout << minimal[n-1][m-1] << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}