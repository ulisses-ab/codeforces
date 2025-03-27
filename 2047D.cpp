#include <bits/stdc++.h>
 
using ll = long long;
using namespace std;
 
int n;
vector<int> v;
vector<bool> b;
 
void testcase() {
    cin >> n;
    
    v.clear();
    b.clear();
    v.resize(n);
    b.resize(n, false);
    
    for(int i = 0; i < n; i++) cin >> v[i];
    int mn = 2000000000;
    int mii = 2000000000;
    int fi = -1;
    for(int i = n - 1; i >= 0; i--) {
        if(v[i] <= mn) {
            mn = v[i];
            continue;
        }
        
        if(fi == -1) fi = i;
        
        b[i] = true;
        v[i]++;
        mii = min(mii, v[i]);
    }
 
    for(int i = n - 1; i >= 0; i--) {
        if(mii < v[i] && b[i] == false) {
            v[i]++;
        }
    }
    
    
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) testcase();
    return 0;
}