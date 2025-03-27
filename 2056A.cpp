#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int x[1], y[1];
 
void testcase() {
    int n, m;
    cin >> n >> m;
 
    int p = 4*m;
    int total = p;
 
    cin >> x[0] >> y[0];
 
    for(int i = 1; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;
 
        int increase = p - (2 *((m - xi) + (m - yi)));
 
        total += increase;
    }
 
    cout << total << endl;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) testcase();
    return 0;
}