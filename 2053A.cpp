#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
void testcase() {
    int n;
    int past;
    cin >> n >> past;
 
    bool ok = false;
 
    for(int i = 1; i < n; i++) {
        int current;
        cin >> current;
        if(past < 2 * current && current < 2 * past) ok = true;
        past = current;
    }
 
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
int main() {
    int t;
    cin >> t;
    while(t--) testcase();
}