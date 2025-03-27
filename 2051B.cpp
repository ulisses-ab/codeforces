#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
ll n, a, b, c;
 
void testcase() {
    cin >> n >> a >> b >> c;
 
    ll total = a + b + c;
 
    ll days = (n / total) * 3;
    n %= total;
 
    if(n > 0) {
        n -= a;
        days++;
    }
    if(n > 0) {
        n -= b;
        days++;
    }
    if(n > 0) {
        n -= c;
        days++;
    }
 
    cout << days << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}