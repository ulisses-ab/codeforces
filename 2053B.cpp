#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
pair<int, int> w[200020];
int a[400040];
bool tree[1600160];
 
bool build(int p, int l, int r) {
    if(l == r) return tree[p] = (a[l] == 0);
    
    ll m = (l + r) / 2;
    
    bool b1 = build((2 * p) + 1, l, m);
    bool b2 = build((2 * p) + 2, m + 1, r);
 
    return tree[p] = b1 || b2;
}
 
bool query(int p, int l, int r, int a, int b) {
    if(b < l || r < a) {
        return false;
    }
    
    if(a <= l && r <= b) return tree[p];
    
    ll m = (l + r) / 2;
    
    bool b1 = query((2 * p) + 1, l, m, a, b);
    bool b2 = query((2 * p) + 2 , m + 1, r, a, b);
    
    return b1 || b2;
}
 
void testcase() {
    int n;
    cin >> n;
 
    for(int i = 1; i <= 2 * n; i++) a[i] = 0;
 
    for(int i = 1; i <= n; i++) {
        cin >> w[i].first >> w[i].second;
        if(w[i].first == w[i].second) {
            a[w[i].first]++;
        }
    }
 
    build(0, 1, 2 * n);
 
    for(int i = 1; i <= n; i++) {
        if(w[i].first == w[i].second) {
            cout << (a[w[i].first] < 2);
        }
        else {
            cout << query(0, 1, 2 * n, w[i].first, w[i].second);
        }
    }
 
    cout << endl;
}
 
int main() {
    int t;
    cin >> t;
    while(t--) testcase();
}
