#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
void testcase() {
    int n; 
    cin >> n;
    
    set<int> a, b;
 
    for(int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        a.insert(ai);
    }
 
    for(int i = 0; i < n; i++) {
        int bi;
        cin >> bi;
        b.insert(bi);
    }
 
    if((a.size() == 2 && b.size() == 2) || a.size() > 2 || b.size() > 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) testcase();
    return 0;
}