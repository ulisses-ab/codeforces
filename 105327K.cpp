#include <bits/stdc++.h>
 
using namespace std;
using lli = unsigned long long int;
 
int n;
int ts = 0;
bool dp[110][10010];
int a[110];
vector<int> v1, v2;
 
bool solve(int pos, int sum) {
    if(sum > ts / 2) return false;
    if(pos == n) return sum == ts / 2;
 
    if(dp[pos][sum]) return false;
    dp[pos][sum] = true;
 
    if(solve(pos + 1, sum + a[pos])) {
        v1.push_back(a[pos]);
        return true;
    }
    if(solve(pos + 1, sum)) {
        v2.push_back(a[pos]);
        return true;
    }
 
    return false;
}
 
int main() {
    cin >> n; 
 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ts += a[i];
    }
 
    if(ts % 2 != 0) {
        cout << "-1" << endl;
        return 0;
    }
 
    int a = 0, b = 0;
    int p1 = 0, p2 = 0;
    vector<int> ans;
 
    if(!solve(0, 0)) {
        cout << "-1" << endl;
        return 0;
    }
 
    while(p1 + p2 < n) {
        if(a <= b) {
            a += v1[p1];
            ans.push_back(v1[p1]);
            p1++;
        }
        else {
            b += v2[p2];
            ans.push_back(v2[p2]);
            p2++;
        }
    }
 
    for(auto x : ans) {
        cout << x << " ";
    }
 
    return 0;
}