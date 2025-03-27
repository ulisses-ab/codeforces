#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
ll n, x, y;
vector<int> a;
 
void testcase() {
    cin >> n >> x >> y;
 
    a.resize(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
 
    sort(a.begin(), a.end());
 
    ll total = 0;
    for(int i = 0; i < n; i++) {
        ll l = sum - a[i] - y, r = sum - a[i] - x;
 
        int il = distance(a.begin(), lower_bound(a.begin(), a.end(), l));
        int ir = distance(a.begin(), --upper_bound(a.begin(), a.end(), r));
 
        il = max(il, i + 1);
 
        total += max(0, ir - il + 1);
    }     
 
    cout << total << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}