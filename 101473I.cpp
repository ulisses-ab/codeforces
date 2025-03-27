#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int n, c, t1, t2, dp[1010][1010];
vector<int> holes;
 
int firstBigger(int p) {
    return distance(holes.begin(), upper_bound(holes.begin(), holes.end(), p));
}
 
int solve(int i, int j) {
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
 
    int minLen = 1000000000;
 
    minLen = min(minLen, t1 + solve(firstBigger(holes[i] + t1), j));
    minLen = min(minLen, t2 + solve(firstBigger(holes[i] + t2), j));
 
    return dp[i][j] = minLen;
}
 
int main() {
    cin >> n >> c >> t1 >> t2;
 
    holes.resize(n);
    for(int i = 0; i < n; i++) cin >> holes[i];
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
 
    int minLen = 1000000000;
 
    minLen = min(minLen, solve(0, n - 1));
 
    for(int i = n - 1; i >= 0; i--) {
        int ep = (holes[i] + t1) - c;
        if(ep < holes[0]) break;
 
        minLen = min(minLen, t1 + solve(firstBigger(ep), i - 1));
    } 
 
    for(int i = n - 1; i >= 0; i--) {
        int ep = (holes[i] + t2) - c;
        if(ep < holes[0]) break;
 
        minLen = min(minLen, t2 + solve(firstBigger(ep), i - 1));
    } 
 
    cout << minLen << endl;
 
    return 0;
}