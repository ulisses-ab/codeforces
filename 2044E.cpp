#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
ll k, l1, r1, l2, r2;
 
void testcase() {
    cin >> k >> l1 >> r1 >> l2 >> r2;
 
    ll c = 1;
    ll total = 0;
    while(c <= 1e9) {
        ll a, b;
 
        a = l2 / c;
        if(l2 % c != 0) a++;
 
        b = r2 / c;
 
        total += max(0ll, min(b, r1) - max(a, l1) + 1ll);
 
        c *= k;
    }
 
    cout << total << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}