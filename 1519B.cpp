#include <bits/stdc++.h>
 
using namespace std;
 
void testcase() {
    int n, m, k;
    cin >> n >> m >> k;
    
    int total = 0;
    total += n - 1;
    total += n * (m - 1);
    
    if(total == k) cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) testcase();
    
    return 0;
}