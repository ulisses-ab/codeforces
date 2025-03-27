#include <bits/stdc++.h>
 
using namespace std;
 
int p[200010];
 
int main() {
    int t;
    cin >> t;
 
    while(t--) {
        int n;
        cin >> n;
 
        for(int i = 0; i < n; i++) cin >> p[i];
 
        bool ok1 = true;
 
        for(int i = 0; i < n; i++) {
            if(abs(p[i] - 1 - i) >= 2) ok1 = false;
        }
        for(int i = 1; i < n; i++) {
            if(p[i] - p[i - 1] < -2) ok1 = false;
        }
 
        if(ok1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
 
    return 0;
}