#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
#define c 1000000007ll
 
ll n, m, k, q, l, r, x, y, z, ma, mb;
 
void testcase() {
    cin >> n;
 
    ll coins = 1;
 
    while(n > 3) {
        n /= 4;
        coins *= 2;
    }
 
    cout << coins << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
 
    return 0;
}