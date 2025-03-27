#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
 
int a[200010];
 
void testcase() {
    ll n, k;
    cin >> n >> k;
    ll on = n;
 
    for(int i = 0; i < on; i++) {
        a[i] = 0;
    }
 
    ll current = 1;
    ll vn = 1;
    while(k > current) {
        vn++;
        current *= 2;
    }
    if(vn > on) {
        cout << -1 << endl;
        return;
    }
 
    int pr = 0, pl = n - 1;
    int val = 1;
 
    while(n > vn) {
        a[pr] = val;
        pr++;
        val++;
        n--;
    }
 
    
    while(current >= 1) {
        current /= 2;
        if(k > current) {
            a[pl] = val;
            val++;
            pl--;
            k -= current;
        }
        else {
            a[pr] = val;
            val++;
            pr++;
        }
    }
 
 
    for(int i = 0; i < on; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
}
 
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}