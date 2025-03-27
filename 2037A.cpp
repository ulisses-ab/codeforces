#include <bits/stdc++.h>
 
using namespace std;
using lli = unsigned long long int;
 
int m[23];
 
void solve() {
    for(auto &x : m) x = 0;
 
    int n; 
    cin >> n;
 
    for(int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        m[ai]++;
    }
 
    int total = 0;
    for(auto x : m) {
        total  += x / 2;
    }
 
    cout << total << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) {
        solve();
    }
    return 0;
}
