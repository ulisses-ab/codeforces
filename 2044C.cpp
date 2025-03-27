#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
void testcase() {
    int m, a, b, c;
    cin >> m >> a >> b >> c;
 
    int total = 0, m1 = m, m2 = m;
 
    if(m1 >= a) {
        m1 -= a;
        total += a;
    }
    else {
        total += m1;
        m1 = 0;
    }
 
    if(m2 >= b) {
        m2 -= b;
        total += b;
    }
    else {
        total += m2;
        m2 = 0;
    }
 
    int free = m1 + m2;
 
    if(free >= c) {
        total += c;
    }
    else {
        total += free;
    }
 
    cout << total << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}