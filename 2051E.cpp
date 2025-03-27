#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
ll n, k;
 
void testcase() {
    cin >> n >> k;
 
    vector<int> a(n), b(n);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
 
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
 
    ll maxProfit = -1;
    for(int i = 0; i < n; i++) {
        ll positive = max(n - i - k, 0ll);
        ll price = positive == 0 ? b[i] : min(b[i], a[n-positive]);
 
        if(i > 0 && price <= b[i-1]) continue;
 
        maxProfit = max(maxProfit, price * (n - i));
    }
 
    cout << maxProfit << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}