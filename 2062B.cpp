#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int a[200010];
 
void testcase() {
    int n;
    cin >> n;
 
    bool ok = true;
    for(int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
 
        if(ai <= i * 2 || ai <= (n - i - 1) * 2) {
            ok = false;
        }
    }
 
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) testcase();
    return 0;
}