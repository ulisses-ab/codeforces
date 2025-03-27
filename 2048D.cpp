#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
void divide(ll x, ll val, vector<ll>& d) {
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            d[i] += val;
            if(x / i != i) d[x / i] += val;
        }
    }
}
 
void testcase() {
    ll n, m;
    cin >> n >> m;
 
    vector<ll> a(n), b(m), d(m+10, 0);
 
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < m; i++) cin >> b[i];
 
    ll v = a[0];
 
    sort(a.begin(), a.end());
 
    for(ll i = 0; i < b.size(); i++) {
        if(b[i] <= v) b[i] = 0;
        else b[i] = distance(lower_bound(a.begin(), a.end(), b[i]), a.end());
    }
 
    sort(b.begin(), b.end());
 
    for(ll i = 0; i < m; i++) {
        divide(i + 1, b[i], d);
    }
 
    for(ll i = 1; i <= m; i++) {
        cout << d[i] + (m / i) << " ";
    }
    cout << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}