
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int a[60];
 
void testcase() {
    int n;
    cin >> n;
 
    for(int i = 0; i < n; i++) cin >> a[i];
 
    int start;
    bool zeroFound = false;
    for(start = 0; start < n; start++) {
        if(a[start] != 0) break;
    }
 
    int end;
    zeroFound = false;
    for(end = n - 1; end >= 0; end--) {
        if(a[end] != 0) break;
    }
 
    zeroFound = false;
    for(int i = start; i <= end; i++) {
        if(a[i] == 0) zeroFound = true;
    }
 
    if(start == n) {
        cout << 0 << endl;
        return;
    }
    if(zeroFound) {
        cout << 2 << endl;
    }
    else {
        cout << 1 << endl;
    }
 
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}