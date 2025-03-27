#include <bits/stdc++.h>
using namespace std;
 
int n, q;
int v[200010];
int tree[800040];
 
int gcd(int a, int b) {
    if(b > a) return gcd(b, a);
    if(b == 0) return a;
    
    return gcd(b, a % b);
}
 
int build(int a, int b, int p) {
    if(a == b) return tree[p] = 0;
    
    int m = (a + b) / 2;
    
    int i1 = build(a, m, (2 * p) + 1);
    int i2 = build(m + 1, b, (2 * p) + 2);
    
    return tree[p] = gcd(gcd(i1, i2), abs(v[m] - v[m+1]));
}
 
int query(int a, int b, int p, int l, int r) {
    if(b < l || r < a) return -1;
    if(l <= a && b <= r) return tree[p];
    
    int m = (a + b) / 2;
    
    int i1 = query(a, m, (2 * p) + 1, l, r);
    int i2 = query(m + 1, b, (2 * p) + 2, l, r);
    
    int d;
    if(i1 == -1 || i2 == -1) {
        if(i1 == -1) return i2;
        else return i1;
    }
    
    return gcd(gcd(i1, i2), abs(v[m] - v[m+1]));
}
 
void print() {
    int p = 0;
    for(int i = 1; i <= 16; i *= 2) {
        for(int j = 0; j < i; j++) {
            cout << tree[j];
            p++;
        }
        cout << endl;
    }
}
 
void testcase() {
    cin >> n >> q;
    
    for(int i = 0; i < n; i++) cin >> v[i];
    
    build(0, n - 1, 0);
    //print();
    
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        
        cout << query(0, n - 1, 0, l, r) << " ";
    }
    cout << endl;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) testcase();
 
    return 0;
}