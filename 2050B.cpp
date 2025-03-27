#include <bits/stdc++.h>
using namespace std;
 
int n;
int a[200010];
 
void solve() {
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> a[i];
    
    long long int sum1 = 0, n1 = 0;
    for(int i = 0; i < n; i += 2) {
        sum1 += a[i];
        n1++;
    }
    
    long long int sum2 = 0, n2 = 0;
    for(int i = 1; i < n; i += 2) {
        sum2 += a[i];
        n2++;
    }
    
    if(sum1 % n1 != 0 || sum2 % n2 != 0) {
        cout << "NO" << endl;
        return;
    }
    
    if(sum1 / n1 != sum2 / n2) {
        cout << "NO" << endl;
        return;
    }
    
    cout << "YES" << endl;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) solve();
 
    return 0;
}
