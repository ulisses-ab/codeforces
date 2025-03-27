#include <bits/stdc++.h>
 
using namespace std;
 
int a[110];
 
void testcase() {
    int n, k;
    cin >> n >> k;
    multiset<int> s;
    s.clear();
 
 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= k;
        s.insert(a[i]);
    }
 
    for(int i = 0; i < n; i++) {
        if(s.count(a[i]) < 2) {
            cout << "YES" << endl << i + 1 << endl;
            return;
        }
    }
 
    cout << "NO" << endl;
 
 
}
 
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}