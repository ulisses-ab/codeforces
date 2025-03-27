#include <bits/stdc++.h>
using namespace std;
 
int dp[1010][1010];
 
void solve() {
    string a, b, c;
    cin >> a >> b >> c;
     
    dp[0][0] = 0;
    
    for(int i = 1; i <= a.size(); i++) {
        dp[i][0] = dp[i-1][0] + (c[i - 1] == a[i - 1]);
    }
    
    for(int i = 1; i <= b.size(); i++) {
        dp[0][i] = dp[0][i-1] + (c[i - 1] == b[i - 1]);
    }
    
    for(int i = 1; i <= a.size(); i++) {
        for(int j = 1; j <= b.size(); j++) {
            dp[i][j] = max(dp[i-1][j] + (c[i+j-1]==a[i-1]), dp[i][j-1] + (c[i+j-1]==b[j-1]));
        }
    }
    
    
    cout << c.size() - dp[a.size()][b.size()] << endl;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) solve();
 
    return 0;
}