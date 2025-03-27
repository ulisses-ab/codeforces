#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int n;
int a[200010], b[200010];
 
void testcase() {
    cin >> n;
 
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
 
    int total = 0;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] > b[i+1]) total += a[i] - b[i+1];
    }
 
    total += a[n-1];
 
    cout << total << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}