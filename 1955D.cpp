#include <bits/stdc++.h>
 
using namespace std;
 
int a[200010], vb[200010];
int b[1000010], c[1000010];
int q;
 
void addC(int x) {
    if(b[x] > c[x]) {
        q++;
    }
 
    c[x]++;
}
 
void removeC(int x) {
    if(b[x] >= c[x]) {
        q--;
    }
    
    c[x]--;
}
 
void testcase() {
    int n, m, k;
    int total = 0;
    cin >> n >> m >> k;
 
    q = 0;
 
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) {
        cin >> vb[i];
    }
 
    for(int i = 0; i < m; i++) {
        b[vb[i]]++;
    }
 
    int s = 0, e = 0; 
    while(e - s + 1 < m) {
        addC(a[e]);
        e++;
    }
    addC(a[e]);
 
    for(; e < n - 1; e++, s++) {
        if(q >= k) total++;
        removeC(a[s]);
        addC(a[e + 1]);
    }
    if(q >= k) total++;
 
    for(int i = 0; i < n; i++) {
        c[a[i]] = 0;
    }
    for(int i = 0; i < m; i++) {
        b[vb[i]] = 0;
    }
 
    cout << total << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    for(auto &x : b) x = 0;
    for(auto &x : c) x = 0;
 
    while(t--) {
        testcase();
    }
}