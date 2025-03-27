#include <bits/stdc++.h>
 
using namespace std;
using lli = long long int;
 
bool isPrimo(lli x) {
 
    for(lli i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
 
    return true;
}
 
lli sqroot(lli x) {
    lli l = 1, h = x;
 
    while(l <= h) {
        lli m = (l + h) / 2;
        //cout << l << "/" << h << ":" << m << endl;
 
        if(m > LONG_LONG_MAX / m) {
            h = m - 1;
            continue;
        }
        
        lli m2 = m * m;
 
        if(m2 == x) return m;
 
        if(m2 < x) {
            l = m + 1;
        }
        else {
            h = m - 1;
        }
    }
 
    return -1;
}
 
int main() {
    int n;
    cin >> n;
 
    for(int i = 0; i < n; i++) {
        lli x;
        cin >> x;
 
        if(x == 1) {
            cout << "NO" << endl;
            continue;
        }
 
        lli sqx = sqroot(x);
        if(sqx == -1 || !isPrimo(sqx)) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}
