#include <bits/stdc++.h>
using namespace std;
 
int n, m;
 
void solve() {
    cin >> n >> m;
    
    int total = 0;
    bool ok = false;
    for(int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        total += s.length();
        if(ok == false && total > m) {
            cout << i << endl;
            ok = true;
        }
    }
    
    if(!ok) cout << n << endl;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) solve();
 
    return 0;
}