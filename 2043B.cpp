#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
#define c 1000000007ll
 
ll n, m, k, q, l, r, x, y, z, ma, mb;
 
void testcase() {
    ll d;
    cin >> n >> d;
 
    cout << 1 << " ";
 
    ll dm3 = d % 3;
    if(n >= 3) {
        cout << 3 << " ";
    }
    else {
        if(dm3 == 0) cout << 3 << " ";
    }
 
    ll dm5 = d % 5;
    if(dm5 == 0) cout << 5 << " ";
 
    ll dm7 = d % 7;
    if(n >= 3) cout << 7 << " ";
    else {
        if(dm7 == 0) cout << 7 << " ";
    }
 
    ll dm9 = d % 9; 
    if(n >= 6) cout << 9 << " ";
    else if(n >= 3) {
        if(dm9 == 3 || dm9 == 6 || dm9 == 0) cout << 9 << " ";
    }
    else {
        if(dm9 == 0) cout << 9 << " ";
    }
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
 
    return 0;
}