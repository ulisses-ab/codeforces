#include <bits/stdc++.h>
 
using namespace std;
using lli = unsigned long long int;
 
unordered_set<int> possible;
 
void solve() {
    int n;
    cin >> n;
 
    if(n <= 4) {
        cout << -1 << endl;
        return;
    }
 
    cout << 2 << " ";
    for(int i = 6; i <= n; i += 2) {
        cout << i << " ";
    }
 
    cout << 4 << " " << 5 << " " << 1 << " " << 3 << " ";
 
    for(int i = 7; i <= n; i += 2) {
        cout << i << " ";
    }
 
    cout << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) {
        solve();
    }
    return 0;
}