#include <bits/stdc++.h>
 
using namespace std;
using lli = unsigned long long int;
 
int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();
 
    int x;
    cin >> x;
    return x;
}
 
void solve() {
    int n;
    cin >> n;
    int a[20010];
    a[0] = 0;
    a[1] = 0;
    string ans = "";
 
    for(int i = 2; i <= n; i++) {
        a[i] = query(1, i);
    }
 
    int i;
    bool ok = false;
    for(i = 1; i <= n; i++) {
        if(a[i] != 0) {
            for(int j = 0; j < i - 1 - a[i]; j++) ans += '1';
            for(int j = 0; j < a[i]; j++) ans += '0';
            ans += '1';
            i++;
            ok = true;
            break;
        }
    }
    if(!ok) {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }
    
    for(; i <= n; i++) {
        if(a[i] == a[i-1]) ans+='0';
        else ans+='1';
    }
 
    cout << "! " + ans << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) {
        solve();
    }
    return 0;
}